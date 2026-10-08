#ifndef ITEM_H
#define ITEM_H
// These guards prevent this structure from being defined more than once.

// Stores information about one grocery item.
struct _Item
{
    double price;    // Item's price.
    char *sku;       // Pointer to the item's SKU string.
    char *name;      // Pointer to the item's name string.
    char *category;  // Pointer to the item's category string.
};

// Allows us to write Item instead of struct _Item.
typedef struct _Item Item;

#endif