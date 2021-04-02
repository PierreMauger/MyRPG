/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_status(game_t *game, mons_t *mons)
{
    if (mons->status->att_p) {
        sfSprite_setPosition(game->status->sprite[att_p], sfSprite_getPosition(mons->texture->sprite));
        sfRenderWindow_drawSprite(GET_WINDOW, game->status->sprite[att_p], NULL);
    }
}
