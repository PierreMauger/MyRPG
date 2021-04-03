/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void status_apply_spe(game_t *game, mons_t *target)
{
    switch (PTR_SKILL_STATUS[CURR_ATT]) {
    case 5:
        target->status->spe_p = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    case 6:
        target->status->spe_m = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    default:
        break;
    }
}

void status_apply(game_t *game, mons_t *target)
{
    switch (PTR_SKILL_STATUS[CURR_ATT]) {
    case 1:
        target->status->att_p = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    case 2:
        target->status->att_m = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    case 3:
        target->status->def_p = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    case 4:
        target->status->def_m = PTR_SKILL_STATUS_TURN[CURR_ATT];
        break;
    default:
        status_apply_spe(game, target);
    }
}
