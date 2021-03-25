/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide(game_t *game, mons_t *mons)
{
    sfVector2f mons_pos = sfSprite_getPosition(MONS_SPRITE(mons));

    mons_pos.x -= MONS_WIDTH(mons) / 2;
    mons_pos.y -= MONS_HEIGHT(mons);
    if (game->mouse_pos.x > mons_pos.x && game->mouse_pos.x < mons_pos.x +
    MONS_WIDTH(mons) && game->mouse_pos.y > mons_pos.y && game->mouse_pos.y
    < mons_pos.y + MONS_HEIGHT(mons))
        return 1;
    return 0;
}

void atb_calc(game_t *game, mons_t *curr_mons)
{
    float temp_atb;

    MONS_CURR_ATB(curr_mons) +=
    game->ind->ptr_skill->stat->atb_boost[CURR_ATT];
    if (MONS_CURR_ATB(curr_mons) <= 0)
        MONS_CURR_ATB(curr_mons) = 0;
    temp_atb = MONS_CURR_ATB(curr_mons);
        if (temp_atb >= 100)
            temp_atb = 100;
    sfRectangleShape_setSize(curr_mons->stat->atb, (sfVector2f){temp_atb, 10});
}

void attack_hit(game_t *game, mons_t *team, mons_t *curr_mons)
{
    atb_calc(game, curr_mons);
    MONS_CURR_HP(curr_mons) -= game->ind->ptr_skill->stat->coef[CURR_ATT];
    if (MONS_CURR_HP(curr_mons) <= 0)
        MONS_CURR_HP(curr_mons) = 0;
    sfRectangleShape_setSize(MONS_HP(curr_mons), (sfVector2f){(float)
    MONS_CURR_HP(curr_mons) / (float)MONS_MAX_HP(curr_mons) * 100, 10});
    if (MONS_CURR_HP(curr_mons) == 0 && CURR_ATT ==
    game->ind->ptr_skill->stat->nbr_hit - 1) {
        kill_mons(game, team, curr_mons);
        game->ind->target = NULL;
    }
    game->set->attack = false;
}

void attack_activation(game_t *game)
{
    mons_t *temp = game->ind->team;

    if (game->ind->ptr_skill->stat->aoe[CURR_ATT] == 1)
        while (temp != NULL) {
            game->ind->target = temp;
            attack_hit(game, game->ind->team, game->ind->target);
            temp = temp->next;
        }
    else
        attack_hit(game, game->ind->team, game->ind->target);
}
