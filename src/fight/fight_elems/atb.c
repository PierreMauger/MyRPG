/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void atb_increase(mons_t *team)
{
    float temp_atb;

    for (mons_t *temp = team; temp; temp = temp->next) {
        MONS_CURR_ATB(temp) += GET_SPE(temp);
        temp_atb = MONS_CURR_ATB(temp);
        if (temp_atb >= 100)
            temp_atb = 100;
        sfRectangleShape_setSize(temp->stat->atb, (sfVector2f){temp_atb, 10});
    }
}

void atb_reset(game_t *game)
{
    MONS_CURR_ATB(game->ind->ptr_mons) = 0;
    sfRectangleShape_setSize(game->ind->ptr_mons->stat->atb,
    (sfVector2f){MONS_CURR_ATB(game->ind->ptr_mons), 10});
}

int check_atb(game_t *game)
{
    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        if (MONS_CURR_ATB(temp) > 100)
            return 1;
    }
    for (mons_t *temp = game->e_mons; temp; temp = temp->next) {
        if (MONS_CURR_ATB(temp) > 100)
            return 1;
    }
    return 0;
}

mons_t *get_higher_atb(game_t *game)
{
    mons_t *result = game->p_mons;

    for (mons_t *temp = game->e_mons; temp; temp = temp->next) {
        if (MONS_CURR_ATB(temp) > MONS_CURR_ATB(result)) {
            result = temp;
            game->set->turn = 1;
        }
    }
    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        if (MONS_CURR_ATB(temp) >= MONS_CURR_ATB(result)) {
            result = temp;
            game->set->turn = 0;
        }
    }
    return result;
}
