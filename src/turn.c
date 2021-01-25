/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void atb_increase(game_t *game, mons_t *mons)
{
    mons_t *temp = mons;

    while (temp != NULL) {
        temp->atb_value += temp->speed;
        sfRectangleShape_setSize(temp->atb, (sfVector2f){temp->atb_value, 10});
        temp = temp->next;
    }
}

void atb_reset(game_t *game)
{
    game->ind->ptr->atb_value = 0;
    sfRectangleShape_setSize(game->ind->ptr->atb, (sfVector2f){game->ind->ptr->atb_value, 10});
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
            game->turn = 1;
        }
        temp2 = temp2->next;
    }
    while (temp != NULL) {
        if (temp->atb_value >= result->atb_value) {
            result = temp;
            game->turn = 0;
        }
        temp = temp->next;
    }
    return result;
}

void turn_loop(game_t *game)
{
    if (check_atb(game) == 1) {
        game->ind->ptr = get_higher_atb(game);
        if (game->attack == 0)
            game->ind->temp = game->ind->ptr->skill;
        game->attack = 1;
    }
    else {
        atb_increase(game, game->e_mons);
        atb_increase(game, game->p_mons);
    }
}
