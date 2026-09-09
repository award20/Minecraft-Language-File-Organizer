#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 1024
#define BUFFER_SIZE 256
#define MAX_TYPES 64
#define TYPE_SIZE 16
#define MOD_ID_SIZE 32
#define PROJECT_NAME_SIZE 32
#define ITEM_NAME_SIZE 64
#define TEXTURE_NAME_SIZE 64
#define INPUT_FILENAME "en_us.json"
#define OUTPUT_FILENAME "output.txt"

struct Item {
    char type[TYPE_SIZE];
    char mod_id[MOD_ID_SIZE];
    char project_name[PROJECT_NAME_SIZE];
    char item_name[ITEM_NAME_SIZE];
    char texture_name[TEXTURE_NAME_SIZE];
};

struct Size {
    size_t type_width;
    size_t mod_id_width;
    size_t project_name_width;
    size_t item_name_width;
    size_t texture_name_width;
};

struct TypeInfo {
    char type[TYPE_SIZE];
    int count;
};

int compare_item_project_names(const void *a, const void *b) {
    const struct Item *item_a = a;
    const struct Item *item_b = b;

    return strcmp(item_a->project_name, item_b->project_name);
}

FILE *open_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("File failed to open");
        return NULL;
    }

    return file;
}

char *remove_leading_whitespace(char *c) {
    while (isspace((unsigned char)*c)) {
        c++;
    }

    return c;
}

char *remove_opening_quotation(char *c) {
    if (*c == '"') {
        c++;
    }

    return c;
}

char *remove_closing_quotation(char *c) {
    char *end = strchr(c, '"');

    if (end != NULL) {
        *end = '\0';
    }

    return c;
}

bool type_has_texture(const char *type) {
    return strcmp(type, "item") == 0
        || strcmp(type, "block") == 0;
}

int read_file(FILE *file, char *buffer, struct Item item[]) {
    int count = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *colon = strchr(buffer, ':');

        if (colon == NULL) {
            continue;
        }

        *colon = '\0';

        char *key = buffer;
        char *value = colon + 1;

        key = remove_leading_whitespace(key);
        value = remove_leading_whitespace(value);

        key = remove_opening_quotation(key);
        value = remove_opening_quotation(value);

        key = remove_closing_quotation(key);
        value = remove_closing_quotation(value);

        // find both periods in the key
        char *first_period = strchr(key, '.');

        if (first_period == NULL) {
            continue;
        }

        char *second_period = strchr(first_period + 1, '.');

        if (second_period == NULL) {
            continue;
        }

        *first_period = '\0';
        *second_period = '\0';

        char *type = key;
        char *mod_id = first_period + 1;
        char *project_name = second_period + 1;

        strcpy(item[count].type, type);
        strcpy(item[count].mod_id, mod_id);
        strcpy(item[count].project_name, project_name);
        strcpy(item[count].item_name, value);

        if (type_has_texture(type)) {
            strcpy(item[count].texture_name, project_name);
            strcat(item[count].texture_name, ".png");
        }

        else {
            item[count].texture_name[0] = '\0';
        }

        count++;

        if (count >= MAX_ENTRIES) {
            break;
        }
    }

    return count;
}

void repeat_character(
    FILE *output,
    size_t type_width,
    size_t mod_id_width,
    size_t project_name_width,
    size_t item_name_width,
    size_t texture_name_width,
    bool include_texture) {

    for (size_t i = 0; i < type_width + 2; i++) {
        fputc('-', output);
    }

    fputc('+', output);

    for (size_t i = 0; i < mod_id_width + 2; i++) {
        fputc('-', output);
    }

    fputc('+', output);

    for (size_t i = 0; i < project_name_width + 2; i++) {
        fputc('-', output);
    }

    fputc('+', output);

    for (size_t i = 0; i < item_name_width + 2; i++) {
        fputc('-', output);
    }

    if (include_texture) {
        fputc('+', output);

        for (size_t i = 0; i < texture_name_width + 2; i++) {
            fputc('-', output);
        }
    }

    fputc('\n', output);
}

struct Size calculate_max_width(
    const char *descriptor,
    struct Item item[],
    int count) {

    bool include_texture = type_has_texture(descriptor);

    struct Size max_width = {
        strlen("Type"),
        strlen("Mod ID"),
        strlen("Project Name"),
        strlen("Display Name"),
        include_texture ? strlen("Texture Name") : 0
    };

    for (int i = 0; i < count; i++) {
        if (strcmp(item[i].type, descriptor) == 0) {
            size_t type_width = strlen(item[i].type);
            size_t mod_id_width = strlen(item[i].mod_id);
            size_t project_name_width = strlen(item[i].project_name);
            size_t item_name_width = strlen(item[i].item_name);

            if (type_width > max_width.type_width) {
                max_width.type_width = type_width;
            }

            if (mod_id_width > max_width.mod_id_width) {
                max_width.mod_id_width = mod_id_width;
            }

            if (project_name_width > max_width.project_name_width) {
                max_width.project_name_width = project_name_width;
            }

            if (item_name_width > max_width.item_name_width) {
                max_width.item_name_width = item_name_width;
            }

            if (include_texture) {
                size_t texture_name_width = strlen(item[i].texture_name);

                if (texture_name_width > max_width.texture_name_width) {
                    max_width.texture_name_width = texture_name_width;
                }
            }
        }
    }

    return max_width;
}

void format_table(
    FILE *output,
    struct Item item[],
    struct TypeInfo type,
    int count) {

    bool include_texture = type_has_texture(type.type);
    struct Size max_width = calculate_max_width(type.type, item, count);

    fprintf(output, "%s\n", type.type);

    if (include_texture) {
        char *display_name = (strcmp(type.type, "item") == 0) ? "Item Name" : "Block Name";
        fprintf(output, " %-*s | %-*s | %-*s | %-*s | %-*s\n",
            (int)max_width.type_width, "Type",
            (int)max_width.mod_id_width, "Mod ID",
            (int)max_width.project_name_width, "Project Name",
            (int)max_width.item_name_width, display_name,            
            (int)max_width.texture_name_width, "Texture Name");
    }

    else {
        fprintf(output, " %-*s | %-*s | %-*s | %-*s\n",
            (int)max_width.type_width, "Type",
            (int)max_width.mod_id_width, "Mod ID",
            (int)max_width.project_name_width, "Project Name",
            (int)max_width.item_name_width, "Display Name");
    }

    repeat_character(
        output,
        max_width.type_width,
        max_width.mod_id_width,
        max_width.project_name_width,
        max_width.item_name_width,
        max_width.texture_name_width,
        include_texture
    );

    for (int i = 0; i < count; i++) {
        if (strcmp(item[i].type, type.type) == 0) {
            if (include_texture) {
                fprintf(output, " %-*s | %-*s | %-*s | %-*s | %-*s\n",
                    (int)max_width.type_width, item[i].type,
                    (int)max_width.mod_id_width, item[i].mod_id,
                    (int)max_width.project_name_width, item[i].project_name,
                    (int)max_width.item_name_width, item[i].item_name,
                    (int)max_width.texture_name_width, item[i].texture_name);
            }

            else {
                fprintf(output, " %-*s | %-*s | %-*s | %-*s\n",
                    (int)max_width.type_width, item[i].type,
                    (int)max_width.mod_id_width, item[i].mod_id,
                    (int)max_width.project_name_width, item[i].project_name,
                    (int)max_width.item_name_width, item[i].item_name);
            }
        }
    }

    fprintf(output, "\n");
}

int discover_types(
    struct Item item[],
    struct TypeInfo type[],
    int count) {

    int type_count = 0;

    for (int i = 0; i < count; i++) {
        bool found = false;

        for (int j = 0; j < type_count; j++) {
            if (strcmp(item[i].type, type[j].type) == 0) {
                type[j].count++;
                found = true;
                break;
            }
        }

        if (!found) {
            if (type_count >= MAX_TYPES) {
                break;
            }

            strcpy(type[type_count].type, item[i].type);
            type[type_count].count = 1;
            type_count++;
        }
    }

    return type_count;
}

size_t calculate_max_type_width(
    struct TypeInfo type[],
    int type_count) {

    size_t max_width = strlen("Type");

    for (int i = 0; i < type_count; i++) {
        size_t type_width = strlen(type[i].type);

        if (type_width > max_width) {
            max_width = type_width;
        }
    }

    return max_width;
}

void format_header_table(
    FILE *output,
    struct TypeInfo type[],
    int type_count) {

    size_t max_type_width = calculate_max_type_width(type, type_count);
    size_t max_count_width = strlen("Count");

    fprintf(output, " %-*s | %*s\n",
        (int)max_type_width, "Type",
        (int)max_count_width, "Count");

    for (size_t i = 0; i < max_type_width + 2; i++) {
        fputc('-', output);
    }

    fputc('+', output);

    for (size_t i = 0; i < max_count_width + 2; i++) {
        fputc('-', output);
    }

    fputc('\n', output);

    for (int i = 0; i < type_count; i++) {
        fprintf(output, " %-*s | %*d\n",
            (int)max_type_width, type[i].type,
            (int)max_count_width, type[i].count);
    }
}

void print_header(
    FILE *output,
    struct Item item[],
    struct TypeInfo type[],
    int count,
    int type_count) {

    int mod_name_length = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(item[i].type, "itemGroup") == 0) {
            fprintf(output, "%s\n", item[i].item_name);
            mod_name_length = strlen(item[i].item_name);
            break;
        }
    }

    for (int i = 0; i < mod_name_length; i++) {
        fputc('=', output);
    }

    fprintf(output, "\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(item[i].type, "itemGroup") == 0) {
            fprintf(output, "Mod Name:\t\t%s\n", item[i].item_name);
            fprintf(output, "Mod ID:\t\t\t%s\n", item[i].mod_id);
            fprintf(output, "Input File:\t\t%s\n", INPUT_FILENAME);
            fprintf(output, "Output File:\t%s\n", OUTPUT_FILENAME);

            fprintf(output, "\nEntry Types\n");

            for (size_t j = 0; j < strlen("Entry Types"); j++) {
                fputc('-', output);
            }

            fprintf(output, "\n");
            fprintf(output, "Total Entries:\t%d\n\n", count);

            format_header_table(
                output,
                type,
                type_count
            );

            fprintf(output, "\n");
            break;
        }
    }
}

void write_file(
    const char *filename,
    struct Item item[],
    struct TypeInfo type[],
    int count) {

    FILE *output = fopen(filename, "w");

    if (output == NULL) {
        perror("Error opening output file");
        return;
    }

    qsort(item, count, sizeof(struct Item), compare_item_project_names);

    int type_count = discover_types(item, type, count);

    print_header(
        output,
        item,
        type,
        count,
        type_count
    );

    for (int i = 0; i < type_count; i++) {
        format_table(
            output,
            item,
            type[i],
            count
        );
    }

    fclose(output);
}

int main(void) {
    FILE *file = open_file(INPUT_FILENAME);

    if (file == NULL) {
        return 1;
    }

    struct Item item[MAX_ENTRIES];
    struct TypeInfo type[MAX_TYPES];
    char buffer[BUFFER_SIZE];

    int count = read_file(file, buffer, item);

    fclose(file);

    write_file(OUTPUT_FILENAME, item, type, count);

    return 0;
}