/*
** EPITECH PROJECT, 2021
** funcs for inventory
** File description:
** inventory
*/

#include "blib.h"
#include "game.h"

int get_item_index(list_t *inv)
{
    int i = 0;
    list_t *temp = inv;
    if (inv == NULL)
        return i;
    else
        for (i = 0; temp != NULL; i++);
    return i;
}

inventory_t *init_inventory(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));
    inv->list = NULL;
    inv->texture = sfTexture_createFromFile(INV_PATH, NULL);
    inv->sprite = sfSprite_create();
    sfSprite_setTexture(inv->sprite, inv->texture, false);
    return inv;
}

//WIP

void add_item_to_inv(inventory_t *inv, int item_id)
{
    item_t *data = malloc(sizeof(item_t));
    data->is_in_inventory = true;
    data->index = get_item_index(inv->list);
}