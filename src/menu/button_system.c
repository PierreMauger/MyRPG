/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>


void draw_buttons(button_t **list)
{
    game_t *game;
    if (list == NULL || game == NULL)
        return;
    for (unsigned int itr = 0; list[itr]; ++itr) {
        sfRenderWindow_drawSprite(GET_WINDOW, list[itr]->sprite, NULL);
    }
}


void set_btn_pos(button_t *btn, sfVector2f pos)
{
    if (!btn)
        return;
    btn->pos = pos;
    sfSprite_setPosition(btn->sprite, btn->pos);
}

void draw_button(game_t *game, button_t *btn)
{
    sfRenderWindow_drawSprite(GET_WINDOW, btn->sprite, NULL);
}

void set_button_rect(button_t *btn, sfIntRect rect)
{
    if (!btn)
        return;
    sfSprite_setTextureRect(btn->sprite, rect);
}

void set_button_color(button_t *btn, sfColor color)
{
    if (!btn)
        return;
    btn->color = color;
    sfSprite_setColor(btn->sprite, color);
}