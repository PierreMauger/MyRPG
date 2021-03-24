/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void atb_increase(mons_t *team)
{
    mons_t *temp = team;
    float temp_atb;

    while (temp != NULL) {
        MONS_CURR_ATB(temp) += MONS_SPEED(temp);
        temp_atb = MONS_CURR_ATB(temp);
        if (temp_atb >= 100)
            temp_atb = 100;
        sfRectangleShape_setSize(temp->stat->atb, (sfVector2f){temp_atb, 10});
        temp = temp->next;
    }
}

void atb_reset(game_t *game)
{
    MONS_CURR_ATB(game->ind->ptr_mons) = 0;
    sfRectangleShape_setSize(game->ind->ptr_mons->stat->atb, (sfVector2f){MONS_CURR_ATB(game->ind->ptr_mons), 10});
}

int check_atb(game_t *game)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    while (temp != NULL) {
        if (MONS_CURR_ATB(temp) > 100)
            return 1;
        temp = temp->next;
    }
    while (temp2 != NULL) {
        if (MONS_CURR_ATB(temp2) > 100)
            return 1;
        temp2 = temp2->next;
    }
    return 0;
}

mons_t *get_higher_atb(game_t *game)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;
    mons_t *result = temp;

    while (temp2 != NULL) {
        if (MONS_CURR_ATB(temp2) > MONS_CURR_ATB(result)) {
            result = temp2;
            game->set->turn = 1;
        }
        temp2 = temp2->next;
    }
    while (temp != NULL) {
        if (MONS_CURR_ATB(temp) >= MONS_CURR_ATB(result)) {
            result = temp;
            game->set->turn = 0;
        }
        temp = temp->next;
    }
    return result;
}
