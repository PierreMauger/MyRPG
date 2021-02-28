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

void passive_action(game_t *game, mons_t *target)
{
    skill_t *temp = game->ind->ptr_skill;

    if (target == NULL)
        return;
    while (temp != NULL) {
        if (temp->passive != 1)
            temp = temp->next;
        else
            break;
    }
    if (temp->name == 'g' && target->atb_value == 0 && temp->act_cd == 0) {
        game->ind->ptr_skill = game->ind->ptr_mons->skill;
        set_anim_pos(game, game->ind->target);
        game->in_anim = true;
        temp->act_cd = 1;
    }
}

void multi_hit(game_t *game, mons_t *target)
{
    if (target == NULL)
        return;
    if (game->ind->curr_attack < 3) {
        set_anim_pos(game, game->ind->target);
        game->in_anim = true;
        game->ind->curr_attack += 1;
    }
    //else
    //    game->ind->curr_attack = 0;
}
