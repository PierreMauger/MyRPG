/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_passive(game_t *game)
{
    skill_t *temp = game->ind->ptr_skill;

    while (temp != NULL) {
        if (temp->passive == 1)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void passive_action(game_t *game, mons_t *mons_list, mons_t *curr_mons)
{
    skill_t *temp = game->ind->ptr_skill;

    if (curr_mons == NULL)
        return;
    while (temp != NULL) {
        if (temp->passive != 1)
            temp = temp->next;
        else
            break;
    }
    if (temp->name == 'g' && curr_mons->atb_value == 0) {
        game->ind->ptr_skill = game->ind->ptr_mons->skill;
        game->in_anim = 1;
        game->ind->target->atb_value = 31;
    }
}