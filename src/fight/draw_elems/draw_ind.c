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
        sfSprite_setOrigin(game->ind->arr->sprite,
        sfSprite_getOrigin(PTR_MONS_SPRITE));
        sfSprite_setPosition(game->ind->arr->sprite, (sfVector2f)
        {sfSprite_getPosition(PTR_MONS_SPRITE).x + (PTR_MONS_WIDTH - 40) / 2,
        sfSprite_getPosition(PTR_MONS_SPRITE).y - 80});
        sfSprite_setTexture(game->ind->arr->sprite, game->ind->arr->texture,
        sfTrue);
        sfSprite_setTextureRect(game->ind->arr->sprite, game->ind->arr->rect);
        sfRenderTexture_drawSprite(GET_BUFFER, game->ind->arr->sprite, NULL);
    }
}
