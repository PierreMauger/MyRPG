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
        if (temp->stat->passive == 1)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void passive_action(game_t *game, mons_t *target)
{
    skill_t *temp = game->ind->ptr_skill;

    if (target == NULL)
        return;
    while (temp != NULL) {
        if (temp->stat->passive != 1)
            temp = temp->next;
        else
            break;
    }
    if (temp->stat->name == 'g' && MONS_CURR_ATB(target) == 0 && temp->stat->act_cd == 0) {
        game->ind->ptr_skill = game->ind->ptr_mons->skill;
        set_attack_anim_pos(game, game->ind->target);
        game->set->in_anim = true;
        temp->stat->act_cd = 1;
    }
}