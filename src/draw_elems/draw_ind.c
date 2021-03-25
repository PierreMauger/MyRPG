/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_turn_ind(game_t *game)
{
    if (game->ind->ptr_mons != NULL) {
        sfSprite_setOrigin(game->ind->sprite,
        sfSprite_getOrigin(PTR_MONS_SPRITE));
        sfSprite_setPosition(game->ind->sprite, (sfVector2f)
        {sfSprite_getPosition(PTR_MONS_SPRITE).x + (PTR_MONS_WIDTH - 40) / 2,
        sfSprite_getPosition(PTR_MONS_SPRITE).y - 80});
        sfSprite_setTexture(game->ind->sprite, game->ind->texture, sfTrue);
        sfSprite_setTextureRect(game->ind->sprite, game->ind->rect);
        sfRenderWindow_drawSprite(GET_WINDOW, game->ind->sprite, NULL);
    }
}
