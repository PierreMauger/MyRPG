/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void anim_all(game_t *game)
{
    GET_SECONDS = sfTime_asSeconds(sfClock_getElapsedTime(GET_CLOCK));
    if (GET_SECONDS > ANIME_TIME) {
        anim_mons(game);
        move_rect(&game->ind->rect, 40, 80);
        if (game->set->in_anim == true) {
            bool_move_rect(&game->ind->ptr_skill->anim->rect, game->ind->ptr_skill->anim->rect.width, game->ind->ptr_skill->anim->rect.width * game->ind->ptr_skill->stat->anim_nb, &game->set->in_anim);
            if (game->set->in_anim == false)
                attack_activation(game);
        }
        sfClock_restart(GET_CLOCK);
    }
}
