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

inventory_t *init_inventory(game_t *game)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->list = NULL;
    inv->invtexture = sfTexture_createFromFile(INV_PATH, NULL);
    inv->invsprite = sfSprite_create();
    inv->selectexture = sfTexture_createFromFile(SELEC_PATH, NULL);
    inv->selecsprite = sfSprite_create();
    inv->pos.x = (sfRenderWindow_getSize(GET_WINDOW).x / 2) - 175;
    inv->pos.y = (sfRenderWindow_getSize(GET_WINDOW).y - 140);
    sfSprite_setTexture(inv->invsprite, inv->invtexture, sfTrue);
    sfSprite_setTexture(inv->selecsprite, inv->selectexture, sfTrue);
    return inv;
}

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

void add_item_to_inv(inventory_t *inv, int item_id)
{
    item_t *data = create_item(item_id);

    data->is_in_inventory = true;
    data->index = get_item_index(inv->list);
    data->pos.x = (inv->pos.x + 5.f) + (30 * data->index);
    data->pos.y = inv->pos.y + 3.f;
    list_stack(&(inv->list), data);
}

// Still to do

void draw_inventory(game_t *game, inventory_t *inv)
{
    bprintf("test\n");
    game->in_inv = false;
    return;
}
