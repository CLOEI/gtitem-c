#include "gtitem.h"
#include <stdio.h>

int main()
{
  struct ItemDatabase *db = parse_from_file("items.dat");
  if (db == NULL)
  {
    return 1;
  }
  printf("Version: %d | Item count: %d\nFirst item name: %s\n Last item name: %s\n", db->version, db->item_count, db->items[0].name, db->items[14539].name);

  return 0;
}