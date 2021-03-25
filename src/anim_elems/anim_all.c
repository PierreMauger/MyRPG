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
        move_rect(&game->ind->arr->rect, 40, 2);
        if (game->set->in_anim == true) {
            bool_move_rect(&PTR_SKILL_ANIM_RECT, PTR_SKILL_ANIM_RECT.width,
            PTR_SKILL_ANIM_NB, &game->set->in_anim);
            if (game->set->in_anim == false)
                attack_activation(game);
        }
        sfClock_restart(GET_CLOCK);
    }
}
