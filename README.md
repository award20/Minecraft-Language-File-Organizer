# Minecraft 
# Language File Organizer
A small C program that reads a Minecraft `en_us.json` language file and generates a formatted `output.txt` report.

The program parses translation entries, sorts them alphabetically, automatically discovers translation types, and organizes them into readable tables.

### Building
Compile with GCC

`gcc main.c -o main`

Run the program in the same directory as `en_us.json`

`./main`

### Alternative Option for Windows
Download `MinecraftLanguageFileOrganizer.exe` and put it in the same directory as `en_us.json`

Double click `MinecraftLanguageFileOrganizer.exe` or run `.\MinecraftLanguageFileOrganizer.exe` in terminal
___
### Example Output

`output.txt`
```
Grand Test Mod
==============
Mod Name:		Grand Test Mod
Mod ID:			grandtestmod
Input File:		en_us.json
Output File:	output.txt

Entry Types
-----------
Total Entries:	128

 Type        | Count
-------------+-------
 item        |    12
 block       |    11
 gui         |    14
 advancement |     5
 entity      |     5
 effect      |     6
 itemGroup   |     1
 container   |    17
 tooltip     |    21
 message     |    36

item
 Type | Mod ID       | Project Name    | Item Name              | Texture Name       
------+--------------+-----------------+------------------------+---------------------
 item | grandtestmod | apple_diced_01  | Diced Apple Variant 1  | apple_diced_01.png 
 item | grandtestmod | apple_diced_02  | Diced Apple Variant 2  | apple_diced_02.png 
 item | grandtestmod | apple_diced_03  | Diced Apple Variant 3  | apple_diced_03.png 
 item | grandtestmod | apple_diced_04  | Diced Apple Variant 4  | apple_diced_04.png 
 item | grandtestmod | apple_diced_05  | Diced Apple Variant 5  | apple_diced_05.png 
 item | grandtestmod | apple_raw_01    | Raw Apple Variant 1    | apple_raw_01.png   
 item | grandtestmod | apple_raw_02    | Raw Apple Variant 2    | apple_raw_02.png   
 item | grandtestmod | apple_raw_03    | Raw Apple Variant 3    | apple_raw_03.png   
 item | grandtestmod | apple_sliced_01 | Sliced Apple Variant 1 | apple_sliced_01.png
 item | grandtestmod | apple_sliced_02 | Sliced Apple Variant 2 | apple_sliced_02.png
 item | grandtestmod | apple_sliced_03 | Sliced Apple Variant 3 | apple_sliced_03.png
 item | grandtestmod | apple_sliced_04 | Sliced Apple Variant 4 | apple_sliced_04.png

block
 Type  | Mod ID       | Project Name | Block Name   | Texture Name    
-------+--------------+--------------+--------------+------------------
 block | grandtestmod | block_01     | Block 1      | block_01.png    
 block | grandtestmod | block_02     | Block 2      | block_02.png    
 block | grandtestmod | block_03     | Block 3      | block_03.png    
 block | grandtestmod | block_04     | Block 4      | block_04.png    
 block | grandtestmod | block_05     | Block 5      | block_05.png    
 block | grandtestmod | new_block_01 | New Block 1  | new_block_01.png
 block | grandtestmod | new_block_02 | New Block 2  | new_block_02.png
 block | grandtestmod | new_block_03 | New Block 3  | new_block_03.png
 block | grandtestmod | new_block_04 | New Block 4  | new_block_04.png
 block | grandtestmod | new_block_05 | New Block 5  | new_block_05.png
 block | grandtestmod | new_block_06 | New Block 6  | new_block_06.png

gui
 Type | Mod ID       | Project Name | Display Name       
------+--------------+--------------+---------------------
 gui  | grandtestmod | button_01    | Interface Button 1 
 gui  | grandtestmod | button_02    | Interface Button 2 
 gui  | grandtestmod | button_03    | Interface Button 3 
 gui  | grandtestmod | button_04    | Interface Button 4 
 gui  | grandtestmod | button_05    | Interface Button 5 
 gui  | grandtestmod | button_06    | Interface Button 6 
 gui  | grandtestmod | button_07    | Interface Button 7 
 gui  | grandtestmod | button_08    | Interface Button 8 
 gui  | grandtestmod | button_09    | Interface Button 9 
 gui  | grandtestmod | button_10    | Interface Button 10
 gui  | grandtestmod | button_11    | Interface Button 11
 gui  | grandtestmod | button_12    | Interface Button 12
 gui  | grandtestmod | button_13    | Interface Button 13
 gui  | grandtestmod | button_14    | Interface Button 14

advancement
 Type        | Mod ID       | Project Name | Display Name
-------------+--------------+--------------+--------------
 advancement | grandtestmod | challenge_01 | Challenge 1 
 advancement | grandtestmod | challenge_02 | Challenge 2 
 advancement | grandtestmod | challenge_03 | Challenge 3 
 advancement | grandtestmod | challenge_04 | Challenge 4 
 advancement | grandtestmod | challenge_05 | Challenge 5 

entity
 Type   | Mod ID       | Project Name | Display Name   
--------+--------------+--------------+-----------------
 entity | grandtestmod | creature_01  | Test Creature 1
 entity | grandtestmod | creature_02  | Test Creature 2
 entity | grandtestmod | creature_03  | Test Creature 3
 entity | grandtestmod | creature_04  | Test Creature 4
 entity | grandtestmod | creature_05  | Test Creature 5

effect
 Type   | Mod ID       | Project Name | Display Name 
--------+--------------+--------------+---------------
 effect | grandtestmod | effect_01    | Test Effect 1
 effect | grandtestmod | effect_02    | Test Effect 2
 effect | grandtestmod | effect_03    | Test Effect 3
 effect | grandtestmod | effect_04    | Test Effect 4
 effect | grandtestmod | effect_05    | Test Effect 5
 effect | grandtestmod | effect_06    | Test Effect 6

itemGroup
 Type      | Mod ID       | Project Name   | Display Name  
-----------+--------------+----------------+----------------
 itemGroup | grandtestmod | grand_test_mod | Grand Test Mod

container
 Type      | Mod ID       | Project Name           | Display Name         
-----------+--------------+------------------------+-----------------------
 container | grandtestmod | machine_001.panel.side | Machine 1 Side Panel 
 container | grandtestmod | machine_002.storage    | Machine 2 Storage    
 container | grandtestmod | machine_003.panel.main | Machine 3 Main Panel 
 container | grandtestmod | machine_004.panel.side | Machine 4 Side Panel 
 container | grandtestmod | machine_005.storage    | Machine 5 Storage    
 container | grandtestmod | machine_006.panel.main | Machine 6 Main Panel 
 container | grandtestmod | machine_007.panel.side | Machine 7 Side Panel 
 container | grandtestmod | machine_008.storage    | Machine 8 Storage    
 container | grandtestmod | machine_009.panel.main | Machine 9 Main Panel 
 container | grandtestmod | machine_010.panel.side | Machine 10 Side Panel
 container | grandtestmod | machine_011.storage    | Machine 11 Storage   
 container | grandtestmod | machine_012.panel.main | Machine 12 Main Panel
 container | grandtestmod | machine_013.panel.side | Machine 13 Side Panel
 container | grandtestmod | machine_014.storage    | Machine 14 Storage   
 container | grandtestmod | machine_015.panel.main | Machine 15 Main Panel
 container | grandtestmod | machine_016.panel.side | Machine 16 Side Panel
 container | grandtestmod | machine_017.storage    | Machine 17 Storage   

tooltip
 Type    | Mod ID       | Project Name | Display Name       
---------+--------------+--------------+---------------------
 tooltip | grandtestmod | property_001 | Tooltip Property 1 
 tooltip | grandtestmod | property_002 | Tooltip Property 2 
 tooltip | grandtestmod | property_003 | Tooltip Property 3 
 tooltip | grandtestmod | property_004 | Tooltip Property 4 
 tooltip | grandtestmod | property_005 | Property 5: %s     
 tooltip | grandtestmod | property_006 | Tooltip Property 6 
 tooltip | grandtestmod | property_007 | Progress 7: %s/%s  
 tooltip | grandtestmod | property_008 | Tooltip Property 8 
 tooltip | grandtestmod | property_009 | Tooltip Property 9 
 tooltip | grandtestmod | property_010 | Property 10: %s    
 tooltip | grandtestmod | property_011 | Tooltip Property 11
 tooltip | grandtestmod | property_012 | Tooltip Property 12
 tooltip | grandtestmod | property_013 | Tooltip Property 13
 tooltip | grandtestmod | property_014 | Progress 14: %s/%s 
 tooltip | grandtestmod | property_015 | Property 15: %s    
 tooltip | grandtestmod | property_016 | Tooltip Property 16
 tooltip | grandtestmod | property_017 | Tooltip Property 17
 tooltip | grandtestmod | property_018 | Tooltip Property 18
 tooltip | grandtestmod | property_019 | Tooltip Property 19
 tooltip | grandtestmod | property_020 | Property 20: %s    
 tooltip | grandtestmod | property_021 | Progress 21: %s/%s 

message
 Type    | Mod ID       | Project Name       | Display Name                       
---------+--------------+--------------------+-------------------------------------
 message | grandtestmod | status_message_001 | Process 1 is waiting for input     
 message | grandtestmod | status_message_002 | Process 2 progress: %s%%           
 message | grandtestmod | status_message_003 | Process 3 is currently unavailable 
 message | grandtestmod | status_message_004 | Process 4 completed successfully   
 message | grandtestmod | status_message_005 | Process 5 is waiting for input     
 message | grandtestmod | status_message_006 | Process 6 progress: %s%%           
 message | grandtestmod | status_message_007 | Process 7 is currently unavailable 
 message | grandtestmod | status_message_008 | Process 8 completed successfully   
 message | grandtestmod | status_message_009 | Process 9 is waiting for input     
 message | grandtestmod | status_message_010 | Process 10 progress: %s%%          
 message | grandtestmod | status_message_011 | Process 11 is currently unavailable
 message | grandtestmod | status_message_012 | Process 12 completed successfully  
 message | grandtestmod | status_message_013 | Process 13 is waiting for input    
 message | grandtestmod | status_message_014 | Process 14 progress: %s%%          
 message | grandtestmod | status_message_015 | Process 15 is currently unavailable
 message | grandtestmod | status_message_016 | Process 16 completed successfully  
 message | grandtestmod | status_message_017 | Process 17 is waiting for input    
 message | grandtestmod | status_message_018 | Process 18 progress: %s%%          
 message | grandtestmod | status_message_019 | Process 19 is currently unavailable
 message | grandtestmod | status_message_020 | Process 20 completed successfully  
 message | grandtestmod | status_message_021 | Process 21 is waiting for input    
 message | grandtestmod | status_message_022 | Process 22 progress: %s%%          
 message | grandtestmod | status_message_023 | Process 23 is currently unavailable
 message | grandtestmod | status_message_024 | Process 24 completed successfully  
 message | grandtestmod | status_message_025 | Process 25 is waiting for input    
 message | grandtestmod | status_message_026 | Process 26 progress: %s%%          
 message | grandtestmod | status_message_027 | Process 27 is currently unavailable
 message | grandtestmod | status_message_028 | Process 28 completed successfully  
 message | grandtestmod | status_message_029 | Process 29 is waiting for input    
 message | grandtestmod | status_message_030 | Process 30 progress: %s%%          
 message | grandtestmod | status_message_031 | Process 31 is currently unavailable
 message | grandtestmod | status_message_032 | Process 32 completed successfully  
 message | grandtestmod | status_message_033 | Process 33 is waiting for input    
 message | grandtestmod | status_message_034 | Process 34 progress: %s%%          
 message | grandtestmod | status_message_035 | Process 35 is currently unavailable
 message | grandtestmod | status_message_036 | Process 36 completed successfully  
```

___
### Example input

`en_us.json`
```
{
    "itemGroup.grandtestmod.grand_test_mod": "Grand Test Mod",
    "item.grandtestmod.apple_raw_01": "Raw Apple Variant 1",
    "item.grandtestmod.apple_raw_02": "Raw Apple Variant 2",
    "item.grandtestmod.apple_raw_03": "Raw Apple Variant 3",
    "item.grandtestmod.apple_sliced_01": "Sliced Apple Variant 1",
    "item.grandtestmod.apple_sliced_02": "Sliced Apple Variant 2",
    "item.grandtestmod.apple_sliced_03": "Sliced Apple Variant 3",
    "item.grandtestmod.apple_sliced_04": "Sliced Apple Variant 4",
    "item.grandtestmod.apple_diced_01": "Diced Apple Variant 1",
    "item.grandtestmod.apple_diced_02": "Diced Apple Variant 2",
    "item.grandtestmod.apple_diced_03": "Diced Apple Variant 3",
    "item.grandtestmod.apple_diced_04": "Diced Apple Variant 4",
    "item.grandtestmod.apple_diced_05": "Diced Apple Variant 5",
    "block.grandtestmod.block_01": "Block 1",
    "block.grandtestmod.block_02": "Block 2",
    "block.grandtestmod.block_03": "Block 3",
    "block.grandtestmod.block_04": "Block 4",
    "block.grandtestmod.block_05": "Block 5",
    "block.grandtestmod.new_block_01": "New Block 1",
    "block.grandtestmod.new_block_02": "New Block 2",
    "block.grandtestmod.new_block_03": "New Block 3",
    "block.grandtestmod.new_block_04": "New Block 4",
    "block.grandtestmod.new_block_05": "New Block 5",
    "block.grandtestmod.new_block_06": "New Block 6",
    "container.grandtestmod.machine_001.panel.side": "Machine 1 Side Panel",
    "container.grandtestmod.machine_002.storage": "Machine 2 Storage",
    "container.grandtestmod.machine_003.panel.main": "Machine 3 Main Panel",
    "container.grandtestmod.machine_004.panel.side": "Machine 4 Side Panel",
    "container.grandtestmod.machine_005.storage": "Machine 5 Storage",
    "container.grandtestmod.machine_006.panel.main": "Machine 6 Main Panel",
    "container.grandtestmod.machine_007.panel.side": "Machine 7 Side Panel",
    "container.grandtestmod.machine_008.storage": "Machine 8 Storage",
    "container.grandtestmod.machine_009.panel.main": "Machine 9 Main Panel",
    "container.grandtestmod.machine_010.panel.side": "Machine 10 Side Panel",
    "container.grandtestmod.machine_011.storage": "Machine 11 Storage",
    "container.grandtestmod.machine_012.panel.main": "Machine 12 Main Panel",
    "container.grandtestmod.machine_013.panel.side": "Machine 13 Side Panel",
    "container.grandtestmod.machine_014.storage": "Machine 14 Storage",
    "container.grandtestmod.machine_015.panel.main": "Machine 15 Main Panel",
    "container.grandtestmod.machine_016.panel.side": "Machine 16 Side Panel",
    "container.grandtestmod.machine_017.storage": "Machine 17 Storage",
    "tooltip.grandtestmod.property_001": "Tooltip Property 1",
    "tooltip.grandtestmod.property_002": "Tooltip Property 2",
    "tooltip.grandtestmod.property_003": "Tooltip Property 3",
    "tooltip.grandtestmod.property_004": "Tooltip Property 4",
    "tooltip.grandtestmod.property_005": "Property 5: %s",
    "tooltip.grandtestmod.property_006": "Tooltip Property 6",
    "tooltip.grandtestmod.property_007": "Progress 7: %s/%s",
    "tooltip.grandtestmod.property_008": "Tooltip Property 8",
    "tooltip.grandtestmod.property_009": "Tooltip Property 9",
    "tooltip.grandtestmod.property_010": "Property 10: %s",
    "tooltip.grandtestmod.property_011": "Tooltip Property 11",
    "tooltip.grandtestmod.property_012": "Tooltip Property 12",
    "tooltip.grandtestmod.property_013": "Tooltip Property 13",
    "tooltip.grandtestmod.property_014": "Progress 14: %s/%s",
    "tooltip.grandtestmod.property_015": "Property 15: %s",
    "tooltip.grandtestmod.property_016": "Tooltip Property 16",
    "tooltip.grandtestmod.property_017": "Tooltip Property 17",
    "tooltip.grandtestmod.property_018": "Tooltip Property 18",
    "tooltip.grandtestmod.property_019": "Tooltip Property 19",
    "tooltip.grandtestmod.property_020": "Property 20: %s",
    "tooltip.grandtestmod.property_021": "Progress 21: %s/%s",
    "message.grandtestmod.status_message_001": "Process 1 is waiting for input",
    "message.grandtestmod.status_message_002": "Process 2 progress: %s%%",
    "message.grandtestmod.status_message_003": "Process 3 is currently unavailable",
    "message.grandtestmod.status_message_004": "Process 4 completed successfully",
    "message.grandtestmod.status_message_005": "Process 5 is waiting for input",
    "message.grandtestmod.status_message_006": "Process 6 progress: %s%%",
    "message.grandtestmod.status_message_007": "Process 7 is currently unavailable",
    "message.grandtestmod.status_message_008": "Process 8 completed successfully",
    "message.grandtestmod.status_message_009": "Process 9 is waiting for input",
    "message.grandtestmod.status_message_010": "Process 10 progress: %s%%",
    "message.grandtestmod.status_message_011": "Process 11 is currently unavailable",
    "message.grandtestmod.status_message_012": "Process 12 completed successfully",
    "message.grandtestmod.status_message_013": "Process 13 is waiting for input",
    "message.grandtestmod.status_message_014": "Process 14 progress: %s%%",
    "message.grandtestmod.status_message_015": "Process 15 is currently unavailable",
    "message.grandtestmod.status_message_016": "Process 16 completed successfully",
    "message.grandtestmod.status_message_017": "Process 17 is waiting for input",
    "message.grandtestmod.status_message_018": "Process 18 progress: %s%%",
    "message.grandtestmod.status_message_019": "Process 19 is currently unavailable",
    "message.grandtestmod.status_message_020": "Process 20 completed successfully",
    "message.grandtestmod.status_message_021": "Process 21 is waiting for input",
    "message.grandtestmod.status_message_022": "Process 22 progress: %s%%",
    "message.grandtestmod.status_message_023": "Process 23 is currently unavailable",
    "message.grandtestmod.status_message_024": "Process 24 completed successfully",
    "message.grandtestmod.status_message_025": "Process 25 is waiting for input",
    "message.grandtestmod.status_message_026": "Process 26 progress: %s%%",
    "message.grandtestmod.status_message_027": "Process 27 is currently unavailable",
    "message.grandtestmod.status_message_028": "Process 28 completed successfully",
    "message.grandtestmod.status_message_029": "Process 29 is waiting for input",
    "message.grandtestmod.status_message_030": "Process 30 progress: %s%%",
    "message.grandtestmod.status_message_031": "Process 31 is currently unavailable",
    "message.grandtestmod.status_message_032": "Process 32 completed successfully",
    "message.grandtestmod.status_message_033": "Process 33 is waiting for input",
    "message.grandtestmod.status_message_034": "Process 34 progress: %s%%",
    "message.grandtestmod.status_message_035": "Process 35 is currently unavailable",
    "message.grandtestmod.status_message_036": "Process 36 completed successfully",
    "gui.grandtestmod.button_01": "Interface Button 1",
    "gui.grandtestmod.button_02": "Interface Button 2",
    "gui.grandtestmod.button_03": "Interface Button 3",
    "gui.grandtestmod.button_04": "Interface Button 4",
    "gui.grandtestmod.button_05": "Interface Button 5",
    "gui.grandtestmod.button_06": "Interface Button 6",
    "gui.grandtestmod.button_07": "Interface Button 7",
    "gui.grandtestmod.button_08": "Interface Button 8",
    "gui.grandtestmod.button_09": "Interface Button 9",
    "gui.grandtestmod.button_10": "Interface Button 10",
    "gui.grandtestmod.button_11": "Interface Button 11",
    "gui.grandtestmod.button_12": "Interface Button 12",
    "gui.grandtestmod.button_13": "Interface Button 13",
    "gui.grandtestmod.button_14": "Interface Button 14",
    "effect.grandtestmod.effect_01": "Test Effect 1",
    "effect.grandtestmod.effect_02": "Test Effect 2",
    "effect.grandtestmod.effect_03": "Test Effect 3",
    "effect.grandtestmod.effect_04": "Test Effect 4",
    "effect.grandtestmod.effect_05": "Test Effect 5",
    "effect.grandtestmod.effect_06": "Test Effect 6",
    "entity.grandtestmod.creature_01": "Test Creature 1",
    "entity.grandtestmod.creature_02": "Test Creature 2",
    "entity.grandtestmod.creature_03": "Test Creature 3",
    "entity.grandtestmod.creature_04": "Test Creature 4",
    "entity.grandtestmod.creature_05": "Test Creature 5",
    "advancement.grandtestmod.challenge_01": "Challenge 1",
    "advancement.grandtestmod.challenge_02": "Challenge 2",
    "advancement.grandtestmod.challenge_03": "Challenge 3",
    "advancement.grandtestmod.challenge_04": "Challenge 4",
    "advancement.grandtestmod.challenge_05": "Challenge 5"
}
```
