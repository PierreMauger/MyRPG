/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void animate(game_t *game)
{
    anim_mons(game);
    move_rect(&ARR_RECT, ARR_RECT.width, ARR_ANIM_NB);
    if (game->set->in_anim == true) {
        bool_move_rect(&PTR_SKILL_ANIM_RECT, PTR_SKILL_ANIM_RECT.width,
        PTR_SKILL_ANIM_NB, &game->set->in_anim);
        if (game->set->in_anim == false)
            attack_activation(game);
    }
    GET_SECONDS = 0;
}

void anim_all(game_t *game)
{
    float temp = sfTime_asSeconds(sfClock_restart(GET_CLOCK));

    GET_TOTAL_TIME += temp;
    GET_SECONDS += temp;
    sfShader_setFloatUniform(game->shader->skill, "time", GET_TOTAL_TIME);
    sfShader_setFloatUniform(game->shader->turn, "time", GET_TOTAL_TIME);
    sfShader_setFloatUniform(game->shader->target, "time", GET_TOTAL_TIME);
    sfShader_setFloatUniform(game->shader->snow, "time", GET_TOTAL_TIME);
    sfShader_setFloatUniform(game->shader->rain, "time", GET_TOTAL_TIME);
    if (GET_SECONDS > ANIM_TIME) {
        animate(game);
    }
}
