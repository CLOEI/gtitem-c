# GTITEM-C
Items.dat parser for Growtopia in C

## Usage
```c
#include "gtitem.h"

int main() {
  struct ItemDatabase *db = parse_from_file("items.dat");
  if (db == NULL) {
    return 1;
  }
  printf("Version: %d | Item count: %d\nFirst item name: %s\n Last item name: %s\n", db->version, db->item_count, db->items[0].name, db->items[4299].name); 
}
```

## items.dat Structure Documentation

This documentation provides an overview of the structure used for items in the game, detailing each field's name, type, and purpose.

- `version` (unsigned short int) -> The version number of the items.dat. Used to handle compatibility and feature availability.
- `item_count` (unsigned int) -> The total number of items stored in the file.
- `items` (struct Item*) -> Pointer to the array of item structures, dynamically allocated based on `item_count`.
- `id` (unsigned int) -> Unique identifier for each item. Used to reference items uniquely.
- `flags` (unsigned short int) -> Bit flags representing various boolean attributes or states of an item.
- `type` (char) -> A character indicating the type of the item. Each type may represent a different category or functionality.
- `material` (char) -> Character code representing the material of the item.
- `name` (string) -> The decrypted name of the item. Names are encrypted in the file and decrypted when read.
- `texture_name` (string) -> Name of the texture file associated with the item.
- `texture_hash` (unsigned int) -> Hash value of the texture file, used for validation or indexing.
- `visual_effect` (char) -> Character code indicating any visual effect associated with the item.
- `cooking_ingredient_type` (unsigned int) -> UNKNOWN
- `texture_x` (char), `texture_y` (char) -> Coordinates for the texture's position on a sprite sheet.
- `render_type` (char) -> Character code indicating how the item should be rendered.
- `is_stripey_wallpaper` (char) -> Indicates whether the item is a stripey wallpaper (boolean).
- `collision_type` (char) -> Character code for the type of collision behavior the item has.
- `block_health` (char) -> Health value of the block ( punch count to break ).
- `drop_chance` (unsigned int) -> Probability or mechanism determining how often the item drops.
- `clothing_type` (char) -> Character code indicating the type of clothing, if applicable.
- `rarity` (unsigned short int) -> Numerical value indicating the rarity of the item.
- `max_items` (char) -> Maximum number of these items that can exist in a stack.
- `extra_file_name` (string) -> Name of an additional file associated with the item.
- `extra_file_hash` (unsigned int) -> Hash value of the additional file for validation or indexing.
- `audio_volume` (unsigned int) -> Volume level for any audio associated with the item.
- `pet_name`, `pet_prefix`, `pet_suffix`, `pet_ability` (string) -> Strings related to pet functionality, including names and abilities.
- `seed_base_sprite`, `seed_base_overlay`, `tree_base_sprite`, `tree_base_overlay` (char) -> Character codes for sprites and overlays related to plantable items.
- `base_color`, `overlay_color` (unsigned int) -> Color values for the base and overlay of an item in hexadecimal format (when using this lib, it is in decimal format you must convert it first).
- `ingredient` (unsigned int) -> UNKNOWN
- `grow_time` (unsigned int) -> Time required for a plantable item to grow.
- `val_2`, `is_rayman` (unsigned short int) -> Additional values for specific functionalities or features.
- `extra_options`, `texture_path_2`, `extra_options_2` (string) -> Additional strings for extended functionalities or metadata.
- `data_pos_80` (char[80]) -> A fixed-size array of character data.
- `punch_option` (string) -> Available if `version` >= 11. Specifies options related to the item's interaction when punched.
- Version-specific fields: Fields and operations that depend on the `version` of the database, including conditional seeks and reads to handle format changes over versions.

## Credits
[Badewen](https://github.com/badewen/GrowDocs/blob/master/items_dat/README.md) - Growtopia documentation