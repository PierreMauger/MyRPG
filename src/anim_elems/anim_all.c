/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void anim_all(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        anim_mons(game);
        move_rect(&game->ind->rect, 40, 80);
        if (game->in_anim == true) {
            single_move_rect(&game->ind->ptr_skill->arect, game->ind->ptr_skill->arect.width, game->ind->ptr_skill->arect.width * game->ind->ptr_skill->anim_nb, &game->in_anim);
            if (game->in_anim == false)
                attack_activation(game);
        }
        sfClock_restart(game->clock);
    }
}
