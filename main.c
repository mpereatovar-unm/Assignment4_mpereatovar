// Sources: https://www.geeksforgeeks.org/c/structure-pointer-in-c/,
//


#include <stdio.h>   // printf displays text.
#include <stdlib.h>  // malloc allocates memory; free releases it.
#include <string.h>  // strlen, strcpy, and strcmp work with strings.

#include "item.h"  // Includes our Item structure.

// Adds an item at a specific index in the array.
void add_item(Item *item_list, double price, char *sku, char *category,
              char *name, int index) {
  // Store the price in the selected item.
  item_list[index].price = price;

  // Allocate memory for the SKU and copy the text.
  // +1 provides space for '\0', which marks the end of a string.
  item_list[index].sku = malloc(strlen(sku) + 1);
  strcpy(item_list[index].sku, sku);

  // Allocate memory for the category and copy the text.
  item_list[index].category = malloc(strlen(category) + 1);
  strcpy(item_list[index].category, category);

  // Allocate memory for the name and copy the text.
  item_list[index].name = malloc(strlen(name) + 1);
  strcpy(item_list[index].name, name);
}
// Frees all memory allocated for the items.
void free_items(Item *item_list, int size) {
  // Free the three strings belonging to each item.
  for (int i = 0; i < size; i++) {
    free(item_list[i].sku);
    free(item_list[i].category);
    free(item_list[i].name);
  }

  // Then free the array of structures.
  free(item_list);
}

// Returns the average price of the items.
double average_price(Item *item_list, int size) {
  double total = 0.0;

  // Add together all item prices.
  for (int i = 0; i < size; i++) {
    total += item_list[i].price;
  }

  // Divide the total by the number of items.
  return total / size;
}

// Prints every item in the array.
void print_items(Item *item_list, int size) 
{
  for (int i = 0; i < size; i++) 
  {
    // %s prints strings; %f prints prices.
    printf("###############\n");
    printf("item name = %s\n", item_list[i].name);
    printf("item sku = %s\n", item_list[i].sku);
    printf("item category = %s\n", item_list[i].category);
    printf("item price = %f\n", item_list[i].price);
  }
}

// argc counts command-line arguments, including the program name.
// argv stores the arguments as strings.
int main(int argc, char *argv[]) {
  int size = 5;

  // Allocate space for five items without filling their fields yet.
  Item *item_list = malloc(size * sizeof(Item));

  // Add five ingredients for making tamales.
  // Arguments: array, price, SKU, category, name, index.
  add_item(item_list, 5.50, "19282", "harinas", "masa de maiz", 0);
  add_item(item_list, 4.00, "79862", "envolturas", "hojas de maiz", 1);
  add_item(item_list, 3.75, "45103", "grasas", "manteca de cerdo", 2);
  add_item(item_list, 4.25, "31457", "chiles", "chiles guajillo secos", 3);
  add_item(item_list, 8.50, "14512", "carnes", "espaldilla de cerdo", 4);

  // Display all items and their average price.
  print_items(item_list, size);
  printf("###############\n");
  printf("average price of items = %f\n", average_price(item_list, size));

  // Make sure the user provided a SKU.
  // Example: ./main 14512
  if (argc < 2) {
    printf("usage: %s <sku>\n", argv[0]);
    free_items(item_list, size);
    return 1;
  }

  // argv[1] is the SKU entered after the program name.
  char *sku = argv[1];

  // Begin searching at index 0.
  int ct = 0;

  
  // Check the index first to avoid reading past the array.
  // && skips the second check when ct < size is false.
  while (ct < size && strcmp(item_list[ct].sku, sku) != 0)
   {
    ct++;
  }

  printf("\n");

  // If the index is still inside the array, a match was found.
  if (ct < size) {
    printf("###############\n");
    printf("item name = %s\n", item_list[ct].name);
    printf("item sku = %s\n", item_list[ct].sku);
    printf("item category = %s\n", item_list[ct].category);
    printf("item price = %f\n", item_list[ct].price);
  } else {
    printf("item not found\n");
  }

  // Release the strings and array before exiting.
  free_items(item_list, size);

  return 0;
}