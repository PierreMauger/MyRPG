/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide(mons_t *mons, sfVector2f mouse_pos)
{
    sfVector2f mons_pos = sfSprite_getPosition(mons->sprite);

    mons_pos.x -= mons->width / 2;
    mons_pos.y -= mons->height;
    if (mouse_pos.x > mons_pos.x && mouse_pos.x < mons_pos.x + mons->width && mouse_pos.y > mons_pos.y && mouse_pos.y < mons_pos.y + mons->height)
        return 1;
    return 0;
}

void attack_hit(game_t *game, mons_t *mons_list, mons_t *curr_mons)
{
    float temp_atb;

    game->in_anim = 1;
    set_anim_pos(game, curr_mons);
    curr_mons->curr_hp -= game->ind->ptr_skill->coef;
    if (curr_mons->curr_hp <= 0)
        kill_mons(game, mons_list, curr_mons);
    curr_mons->atb_value += game->ind->ptr_skill->atb_boost;
    if (curr_mons->atb_value <= 0)
        curr_mons->atb_value = 0;
    temp_atb = curr_mons->atb_value;
        if (temp_atb >= 100)
            temp_atb = 100;
    sfRectangleShape_setSize(curr_mons->atb, (sfVector2f){temp_atb, 10});
    sfRectangleShape_setSize(curr_mons->hp, (sfVector2f){((float)curr_mons->curr_hp / (float)curr_mons->max_hp) * 100, 10});
    game->attack = 0;
}

void aoe_hit(game_t *game, mons_t *mons)
{
    mons_t *temp = mons;

    while (temp != NULL) {
        attack_hit(game, mons, temp);
        temp = temp->next;
    }
}

void target_team(game_t *game, mons_t *team, sfVector2i mouse_pos)
{
    mons_t *temp = team;

    while (temp != NULL) {
        if (check_collide(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1) {
            atb_reset(game);
            if (game->ind->ptr_skill->aoe == 1)
                aoe_hit(game, team);
            else
                attack_hit(game, team, temp);
        }
        temp = temp->next;
    }
}

void attack(game_t *game, sfVector2i mouse_pos)
{
    if (game->turn == game->ind->ptr_skill->target)
        target_team(game, game->e_mons, mouse_pos);
    else
        target_team(game, game->p_mons, mouse_pos);
}
