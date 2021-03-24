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
        sfSprite_setOrigin(game->ind->sprite, sfSprite_getOrigin(game->ind->ptr_mons->mons_tex->sprite));
        sfSprite_setPosition(game->ind->sprite, (sfVector2f){sfSprite_getPosition(game->ind->ptr_mons->mons_tex->sprite).x + (game->ind->ptr_mons->mons_tex->rect.width - 40) / 2, sfSprite_getPosition(game->ind->ptr_mons->mons_tex->sprite).y - 80});
        sfSprite_setTexture(game->ind->sprite, game->ind->texture, sfTrue);
        sfSprite_setTextureRect(game->ind->sprite, game->ind->rect);
        sfRenderWindow_drawSprite(game->window->window, game->ind->sprite, NULL);
    }
}
