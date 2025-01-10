#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gtitem.h"

const char *CIPHER = "PBG892FXX982ABC*";

char *decrypt_string(FILE *file, unsigned int item_id)
{
  unsigned short int len = 0;
  fread(&len, sizeof(unsigned short int), 1, file);
  char *str = (char *)malloc(len + 1);
  if (str == NULL)
  {
    perror("Memory allocation failed\n");
    return NULL;
  }

  for (int i = 0; i < len; i++)
  {
    int secret_char_pos = (i + item_id) % strlen(CIPHER);
    char secret_char = CIPHER[secret_char_pos];
    char input_char;
    fread(&input_char, sizeof(char), 1, file);
    str[i] = input_char ^ secret_char;
  }
  str[len] = '\0';
  return str;
}

char *read_string(FILE *file)
{
  unsigned short int len = 0;
  fread(&len, sizeof(unsigned short int), 1, file);
  char *str = (char *)malloc(len + 1);
  if (str == NULL)
  {
    perror("Memory allocation failed\n");
    return NULL;
  }
  fread(str, sizeof(char), len, file);
  str[len] = '\0';
  return str;
}

struct ItemDatabase *parse_from_file(const char *filename)
{
  struct ItemDatabase *db = malloc(sizeof(struct ItemDatabase));
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    perror("Error opening file\n");
    free(db);
    return NULL;
  }

  fread(&db->version, sizeof(unsigned short int), 1, file);
  fread(&db->item_count, sizeof(unsigned int), 1, file);

  db->items = (struct Item *)malloc(db->item_count * sizeof(struct Item));
  if (db->items == NULL)
  {
    perror("Memory allocation failed\n");
    fclose(file);
    free(db);
    return NULL;
  }

  for (unsigned int i = 0; i < db->item_count; i++)
  {
    fread(&db->items[i].id, sizeof(unsigned int), 1, file);
    if (i != db->items[i].id)
    {
      perror("Item ID mismatch\n");
      fclose(file);
      return NULL;
    }

    fread(&db->items[i].flags, sizeof(unsigned short int), 1, file);
    fread(&db->items[i].type, sizeof(char), 1, file);
    fread(&db->items[i].material, sizeof(char), 1, file);
    db->items[i].name = decrypt_string(file, db->items[i].id);
    db->items[i].texture_name = read_string(file);
    fread(&db->items[i].texture_hash, sizeof(unsigned int), 1, file);
    fread(&db->items[i].visual_effect, sizeof(char), 1, file);
    fread(&db->items[i].cooking_ingredient_type, sizeof(unsigned int), 1, file);
    fread(&db->items[i].texture_x, sizeof(char), 1, file);
    fread(&db->items[i].texture_y, sizeof(char), 1, file);
    fread(&db->items[i].render_type, sizeof(char), 1, file);
    fread(&db->items[i].is_stripey_wallpaper, sizeof(char), 1, file);
    fread(&db->items[i].collision_type, sizeof(char), 1, file);
    fread(&db->items[i].block_health, sizeof(char), 1, file);
    fread(&db->items[i].drop_chance, sizeof(unsigned int), 1, file);
    fread(&db->items[i].clothing_type, sizeof(char), 1, file);
    fread(&db->items[i].rarity, sizeof(unsigned short int), 1, file);
    fread(&db->items[i].max_items, sizeof(char), 1, file);
    db->items[i].extra_file_name = read_string(file);
    fread(&db->items[i].extra_file_hash, sizeof(unsigned int), 1, file);
    fread(&db->items[i].audio_volume, sizeof(unsigned int), 1, file);
    db->items[i].pet_name = read_string(file);
    db->items[i].pet_prefix = read_string(file);
    db->items[i].pet_suffix = read_string(file);
    db->items[i].pet_ability = read_string(file);
    fread(&db->items[i].seed_base_sprite, sizeof(char), 1, file);
    fread(&db->items[i].seed_base_overlay, sizeof(char), 1, file);
    fread(&db->items[i].tree_base_sprite, sizeof(char), 1, file);
    fread(&db->items[i].tree_base_overlay, sizeof(char), 1, file);
    fread(&db->items[i].base_color, sizeof(unsigned int), 1, file);
    fread(&db->items[i].overlay_color, sizeof(unsigned int), 1, file);
    fread(&db->items[i].ingredient, sizeof(unsigned int), 1, file);
    fread(&db->items[i].grow_time, sizeof(unsigned int), 1, file);
    fseek(file, sizeof(unsigned short int), SEEK_CUR);
    fread(&db->items[i].is_rayman, sizeof(unsigned short int), 1, file);
    db->items[i].extra_options = read_string(file);
    db->items[i].texture_path_2 = read_string(file);
    db->items[i].extra_options_2 = read_string(file);
    fseek(file, 80, SEEK_CUR);

    if (db->version >= 11)
    {
      db->items[i].punch_option = read_string(file);
    }
    if (db->version >= 12)
    {
      fseek(file, 13, SEEK_CUR);
    }
    if (db->version >= 13)
    {
      fseek(file, 4, SEEK_CUR);
    }
    if (db->version >= 14)
    {
      fseek(file, 4, SEEK_CUR);
    }
    if (db->version >= 15)
    {
      fseek(file, 25, SEEK_CUR);
      read_string(file);
    }
    if (db->version >= 16)
    {
      read_string(file);
    }
    if (db->version >= 17)
    {
      fseek(file, 4, SEEK_CUR);
    }
    if (db->version >= 18)
    {
      fseek(file, 4, SEEK_CUR);
    }
    if (db->version >= 19)
    {
      fseek(file, 9, SEEK_CUR);
    }
  }
  fclose(file);
  db->is_loaded = true;
  return db;
}