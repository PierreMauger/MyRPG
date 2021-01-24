/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void take_turn(game_t *game)
{
    if (game->ind->ptr->next != NULL)
        game->ind->ptr = game->ind->ptr->next;
    else {
        if (game->turn == 0) {
            change_bool(&game->turn);
            game->ind->ptr = game->e_mons;
        }
        else {
            change_bool(&game->turn);
            game->ind->ptr = game->p_mons;
        }
    }
}

void atb_increase(game_t *game, mons_t *mons)
{
    mons_t *temp = mons;

    while (temp != NULL) {
        temp->atb_value += temp->speed;
        sfRectangleShape_setSize(temp->atb, (sfVector2f){temp->atb_value, 10});
        temp = temp->next;
    }
}
