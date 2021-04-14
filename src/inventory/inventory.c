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
    sfSprite_setTexture(inv->sprite, inv->texture, sfTrue);
    return inv;
}

//WIP

item_t *create_item(int id)
{
    struct stat st;
    sfTexture *t;
    item_t *data = malloc(sizeof(item_t));
    char *buf = NULL;

    stat(JSON_ITEMS, &st);
    buf = bread_file(JSON_ITEMS, st.st_size);
    data->description = (char *)parser(buf, "description", id);
    data->name = (char *)parser(buf, "name", id);
    t = sfTexture_createFromFile((char *)parser(buf, "path", id), NULL);
    data->texture = t;
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    data->dmg_buff = (int)parser(buf, "att_buff", id);
    data->def_buff = (int)parser(buf, "def_buff", id);
    data->speed_buff = (int)parser(buf, "speed_buff", id);
    return data;
}

// Need to add pos_init

void add_item_to_inv(inventory_t *inv, int item_id)
{
    item_t *data = create_item(item_id);
    data->is_in_inventory = true;
    data->index = get_item_index(inv->list);
    list_stack(&(inv->list), data);
}