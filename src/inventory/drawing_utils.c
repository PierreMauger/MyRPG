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
    inv->prompttext = sfText_create();
    sfText_setFont(inv->prompttext, game->font);
    sfText_setCharacterSize(inv->prompttext, 15);
    sfText_setColor(inv->prompttext, sfWhite);
}