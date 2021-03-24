/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide(game_t *game, mons_t *mons)
{
    sfVector2f mons_pos = sfSprite_getPosition(mons->mons_tex->sprite);

    mons_pos.x -= mons->mons_tex->rect.width / 2;
    mons_pos.y -= mons->mons_tex->rect.height;
    if (game->mouse_pos.x > mons_pos.x && game->mouse_pos.x < mons_pos.x + mons->mons_tex->rect.width && game->mouse_pos.y > mons_pos.y && game->mouse_pos.y < mons_pos.y + mons->mons_tex->rect.height)
        return 1;
    return 0;
}

void attack_hit(game_t *game, mons_t *team, mons_t *curr_mons)
{
    float temp_atb;

    MONS_CURR_HP(curr_mons) -= game->ind->ptr_skill->coef[CURR_ATT];
    if (MONS_CURR_HP(curr_mons) <= 0) {
        kill_mons(game, team, curr_mons);
        game->ind->target = NULL;
    }
    MONS_CURR_ATB(curr_mons) += game->ind->ptr_skill->atb_boost[CURR_ATT];
    if (MONS_CURR_ATB(curr_mons) <= 0)
        MONS_CURR_ATB(curr_mons) = 0;
    temp_atb = MONS_CURR_ATB(curr_mons);
        if (temp_atb >= 100)
            temp_atb = 100;
    sfRectangleShape_setSize(curr_mons->mons_stat->atb, (sfVector2f){temp_atb, 10});
    sfRectangleShape_setSize(MONS_HP(curr_mons), (sfVector2f){((float)MONS_CURR_HP(curr_mons) / (float)MONS_MAX_HP(curr_mons)) * 100, 10});
    game->set->attack = false;
}

void attack_activation(game_t *game)
{
    mons_t *temp = game->ind->team;

    if (game->ind->ptr_skill->aoe[CURR_ATT] == 1)
        while (temp != NULL) {
            game->ind->target = temp;
            attack_hit(game, game->ind->team, game->ind->target);
            temp = temp->next;
        }
    else
        attack_hit(game, game->ind->team, game->ind->target);
}
