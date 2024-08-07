#ifndef GTITEM_H
#define GTITEM_H

#include <stdio.h>

struct Item
{
  unsigned int id;
  unsigned short int flags;
  char type;
  char material;
  char *name;
  char *texture_name;
  unsigned int texture_hash;
  char visual_effect;
  unsigned int cooking_ingredient_type;
  char texture_x;
  char texture_y;
  char render_type;
  char is_stripey_wallpaper;
  char collision_type;
  char block_health;
  unsigned int drop_chance;
  char clothing_type;
  unsigned short int rarity;
  char max_items;
  char *extra_file_name;
  unsigned int extra_file_hash;
  unsigned int audio_volume;
  char *pet_name;
  char *pet_prefix;
  char *pet_suffix;
  char *pet_ability;
  char seed_base_sprite;
  char seed_base_overlay;
  char tree_base_sprite;
  char tree_base_overlay;
  unsigned int base_color;
  unsigned int overlay_color;
  unsigned int ingredient;
  unsigned int grow_time;
  unsigned short int is_rayman;
  char *extra_options;
  char *texture_path_2;
  char *extra_options_2;
  char *punch_option;
};

struct ItemDatabase
{
  unsigned short int version;
  unsigned int item_count;
  struct Item *items;
};

char *decrypt_string(FILE *file, unsigned int id);
char *read_string(FILE *file);
struct ItemDatabase *parse_from_file(char *filename);

#endif