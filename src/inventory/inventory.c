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
        for (i = 0; temp != NULL; i++, temp = temp->next);
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
    inv->equipedtexture = sfTexture_createFromFile(EQU_PATH, NULL);
    inv->equipedsprite = sfSprite_create();
    inv->promptsprite = sfSprite_create();
    inv->prompttexture = sfTexture_createFromFile(PROMPT_PATH, NULL);
    inv->pos.x = (sfRenderWindow_getSize(GET_WINDOW).x / 2) - 175;
    inv->pos.y = (sfRenderWindow_getSize(GET_WINDOW).y - 140);
    init_prompt_text(inv, game);
    sfSprite_setTexture(inv->invsprite, inv->invtexture, sfTrue);
    sfSprite_setTexture(inv->selecsprite, inv->selectexture, sfTrue);
    sfSprite_setTexture(inv->equipedsprite, inv->equipedtexture, sfTrue);
    sfSprite_setTexture(inv->promptsprite, inv->prompttexture, sfTrue);
    sfSprite_setPosition(inv->invsprite, (sfVector2f){inv->pos.x, inv->pos.y});
    return inv;
}

item_t *create_item(int id)
{
    sfTexture *t;
    item_t *data = malloc(sizeof(item_t));
    char *buf = NULL;
    char *path = NULL;

    buf = bread_file(JSON_ITEMS, 20);
    data->description = (char *)parser(buf, "description", id);
    data->name = (char *)parser(buf, "name", id);
    path = (char *)parser(buf, "path", id);
    t = sfTexture_createFromFile(path, NULL);
    data->texture = t;
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    data->dmg_buff = (int)parser(buf, "att_buff", id);
    data->def_buff = (int)parser(buf, "def_buff", id);
    data->speed_buff = (int)parser(buf, "speed_buff", id);
    free(buf);
    free(path);
    return data;
}

void add_item_to_inv(inventory_t *inv, int item_id)
{
    item_t *data = create_item(item_id);

    data->is_in_inventory = true;
    data->is_equiped = false;
    data->is_active = false;
    data->index = get_item_index(inv->list);
    data->pos.x = (inv->pos.x + 3.f) + (70 * data->index);
    data->pos.y = inv->pos.y + 3.f;
    sfSprite_setPosition(data->sprite, (sfVector2f){data->pos.x, data->pos.y});
    list_stack(&(inv->list), data);
}

int draw_inventory(game_t *game, inventory_t *inv)
{
    int pas = 0;

    inv->selected = 0;
    if (!game->in_inv || game->set->pause == true)
        return 0;
    while (game->in_inv == true) {
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        loop_map(game, &pas);
        sfRenderWindow_drawSprite(GET_WINDOW, inv->invsprite, NULL);
        draw_equiped(game, inv);
        draw_list(GET_WINDOW, inv->list);
        set_selec_pos(inv);
        sfRenderWindow_drawSprite(GET_WINDOW, inv->selecsprite, NULL);
        if (inv->prompt && inv->selected < get_item_index(inv->list))
            display_prompt(inv, game);
        if (poll_inv_events(game, inv) == 1)
            return 1;
        sfRenderWindow_display(GET_WINDOW);
    }
    return 0;
}