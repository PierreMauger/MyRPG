/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void set_anim_pos(game_t *game, mons_t *target)
{
    sfSprite_setOrigin(game->ind->ptr_skill->asprite, (sfVector2f){target->width / 2 + 40, 0});
    sfSprite_setPosition(game->ind->ptr_skill->asprite, (sfVector2f){sfSprite_getPosition(target->sprite).x + target->width / 2, sfSprite_getPosition(target->sprite).y - 80});
    sfText_setPosition(game->ind->damage, (sfVector2f){sfSprite_getPosition(target->sprite).x, sfSprite_getPosition(target->sprite).y - 80});
}
