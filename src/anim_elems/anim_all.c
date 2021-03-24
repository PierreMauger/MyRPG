/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void anim_all(game_t *game)
{
    game->time->time = sfClock_getElapsedTime(game->time->clock);
    game->time->seconds = game->time->time.microseconds / 1000000.0;
    if (game->time->seconds > ANIME_TIME) {
        anim_mons(game);
        move_rect(&game->ind->rect, 40, 80);
        if (game->set->in_anim == true) {
            single_move_rect(&game->ind->ptr_skill->arect, game->ind->ptr_skill->arect.width, game->ind->ptr_skill->arect.width * game->ind->ptr_skill->anim_nb, &game->set->in_anim);
            if (game->set->in_anim == false)
                attack_activation(game);
        }
        sfClock_restart(game->time->clock);
    }
}
