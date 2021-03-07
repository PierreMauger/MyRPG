/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"


void aoe_hit(game_t *game)
{
    mons_t *temp = game->ind->team;

    while (temp != NULL) {
        game->ind->target = temp;
        set_attack_anim(game);
        temp = temp->next;
    }
}

void set_attack_anim(game_t *game)
{
    game->in_anim = true;
    set_attack_anim_pos(game, game->ind->target);
    //if (check_passive(game) == true)
    //    passive_action(game, mons_list, curr_mons);
}

void set_attack_anim_pos(game_t *game, mons_t *target)
{
    sfSprite_setOrigin(game->ind->ptr_skill->asprite, (sfVector2f){target->width / 2 + 40, 0});
    sfSprite_setPosition(game->ind->ptr_skill->asprite, (sfVector2f){sfSprite_getPosition(target->sprite).x + target->width / 2, sfSprite_getPosition(target->sprite).y - 80});
    sfText_setPosition(game->ind->damage, (sfVector2f){sfSprite_getPosition(target->sprite).x, sfSprite_getPosition(target->sprite).y - 80});
}

void multi_hit(game_t *game, mons_t *target)
{
    if (target == NULL || game->ind->ptr_skill == NULL)
        return;
    if (CURR_ATT < game->ind->ptr_skill->nbr_hit - 1) {
        set_attack_anim_pos(game, game->ind->target);
        game->in_anim = true;
        CURR_ATT += 1;
    }
    target_team(game);
}
