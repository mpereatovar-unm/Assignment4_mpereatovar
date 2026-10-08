#include <stdio.h>   // printf displays text.
#include <stdlib.h>  // malloc allocates memory; free releases it.
#include <string.h>  // strlen, strcpy, and strcmp work with strings.
#include "item.h"    // Includes our Item structure.

// Adds an item at a specific index in the array.
void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index)