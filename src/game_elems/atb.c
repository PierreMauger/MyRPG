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
        temp->atb_value += temp->speed;
        temp_atb = temp->atb_value;
        if (temp_atb >= 100)
            temp_atb = 100;
        sfRectangleShape_setSize(temp->atb, (sfVector2f){temp_atb, 10});
        temp = temp->next;
    }
}

void atb_reset(game_t *game)
{
    game->ind->ptr_mons->atb_value = 0;
    sfRectangleShape_setSize(game->ind->ptr_mons->atb, (sfVector2f){game->ind->ptr_mons->atb_value, 10});
}

int check_atb(game_t *game)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    while (temp != NULL) {
        if (temp->atb_value > 100)
            return 1;
        temp = temp->next;
    }
    while (temp2 != NULL) {
        if (temp2->atb_value > 100)
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
        if (temp2->atb_value > result->atb_value) {
            result = temp2;
            game->set->turn = 1;
        }
        temp2 = temp2->next;
    }
    while (temp != NULL) {
        if (temp->atb_value >= result->atb_value) {
            result = temp;
            game->set->turn = 0;
        }
        temp = temp->next;
    }
    return result;
}
