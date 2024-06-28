#include "gtitem.h"
#include <stdio.h>

int main() {
  struct Database *db = parse_from_file("items.dat");
  if (db == NULL) {
    return 1;
  }
  printf("Version: %d | Item count: %d\nFirst item name: %s\n Last item name: %d\n", db->version, db->item_count, db->items[0].name, db->items[4299].id);

  return 0;
}