/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide(game_t *game, mons_t *mons)
{
    sfVector2f mons_pos = sfSprite_getPosition(mons->sprite);

    mons_pos.x -= mons->width / 2;
    mons_pos.y -= mons->height;
    if (game->mouse_pos.x > mons_pos.x && game->mouse_pos.x < mons_pos.x + mons->width && game->mouse_pos.y > mons_pos.y && game->mouse_pos.y < mons_pos.y + mons->height)
        return 1;
    return 0;
}

void attack_hit(game_t *game, mons_t *mons_list, mons_t *curr_mons)
{
    float temp_atb;

    curr_mons->curr_hp -= game->ind->ptr_skill->coef[game->ind->curr_attack];
    if (curr_mons->curr_hp <= 0) {
        kill_mons(game, mons_list, curr_mons);
        game->ind->target = NULL;
    }
    curr_mons->atb_value += game->ind->ptr_skill->atb_boost;
    if (curr_mons->atb_value <= 0)
        curr_mons->atb_value = 0;
    temp_atb = curr_mons->atb_value;
        if (temp_atb >= 100)
            temp_atb = 100;
    sfRectangleShape_setSize(curr_mons->atb, (sfVector2f){temp_atb, 10});
    sfRectangleShape_setSize(curr_mons->hp, (sfVector2f){((float)curr_mons->curr_hp / (float)curr_mons->max_hp) * 100, 10});
    game->attack = false;
}

void set_attack(game_t *game)
{
    game->in_anim = true;
    set_anim_pos(game, game->ind->target);
    //if (check_passive(game) == true)
    //    passive_action(game, mons_list, curr_mons);
}

void aoe_hit(game_t *game)
{
    mons_t *temp = game->ind->team;

    while (temp != NULL) {
        game->ind->target = temp;
        set_attack(game);
        temp = temp->next;
    }
}

void attack(game_t *game)
{
    mons_t *temp;

    if (game->turn == game->ind->ptr_skill->target)
        game->ind->team = game->e_mons;
    else
        game->ind->team = game->p_mons;
    temp = game->ind->team;
    while (temp != NULL) {
        if (check_collide(game, temp) == 1) {
            atb_reset(game);
            game->ind->target = temp;
            if (game->ind->ptr_skill->aoe == 1)
                aoe_hit(game);
            else
                set_attack(game);
            game->ind->ptr_skill->act_cd = game->ind->ptr_skill->ini_cd;
        }
        if (temp != NULL)
            temp = temp->next;
    }
}

void attack_activation(game_t *game)
{
    mons_t *temp = game->ind->team;

    if (game->ind->ptr_skill->aoe == 1)
        while (temp != NULL) {
            game->ind->target = temp;
            attack_hit(game, game->ind->team, game->ind->target);
            temp = temp->next;
        }
    else
        attack_hit(game, game->ind->team, game->ind->target);
}
