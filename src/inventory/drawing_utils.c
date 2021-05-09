/*
** EPITECH PROJECT, 2021
** utils for inv drawing
** File description:
** drawing_utils
*/

#include "game.h"

item_t *get_selected_item(inventory_t *inv)
{
    list_t *temp = inv->list;

    for (int i = 0; temp != NULL && i != inv->selected; i++, temp = temp->next);
    return temp->data;
}

void init_prompt_text(inventory_t *inv, game_t *game)
{
    inv->prompt = false;
    inv->prompttext = sfText_create();
    sfText_setFont(inv->prompttext, game->font);
    sfText_setCharacterSize(inv->prompttext, 15);
    sfText_setColor(inv->prompttext, sfWhite);
}

void set_string(inventory_t *inv, item_t *item, int id)
{
    char *str = NULL;

    if (id == 1) {
        str = bitoa(item->dmg_buff);
        sfText_setString(inv->prompttext, str);
        free(str);
    }
    if (id == 2) {
        str = bitoa(item->def_buff);
        sfText_setString(inv->prompttext, str);
        free(str);
    }
    if (id == 3) {
        str = bitoa(item->speed_buff);
        sfText_setString(inv->prompttext, str);
        free(str);
    }
}