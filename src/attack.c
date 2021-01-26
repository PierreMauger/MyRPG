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
    curr_mons->curr_hp -= game->ind->ptr_skill->coef;
    if (curr_mons->curr_hp <= 0)
        kill_mons(game, mons_list, curr_mons);
    sfRectangleShape_setSize(curr_mons->hp, (sfVector2f){((float)curr_mons->curr_hp / (float)curr_mons->max_hp) * 100, 10});
    atb_reset(game);
    game->attack = 0;
}

void target_enemy(game_t *game, mons_t *temp, sfVector2i mouse_pos)
{
    while (temp != NULL) {
        if (game->ind->ptr_skill->aoe == 1)
            attack_hit(game, game->e_mons, temp);
        else if (check_collide(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
            attack_hit(game, game->e_mons, temp);
        temp = temp->next;
    }
}

void target_ally(game_t *game, mons_t *temp, sfVector2i mouse_pos)
{
    while (temp != NULL) {
        if (check_collide(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
            attack_hit(game, game->p_mons, temp);
        temp = temp->next;
    }
}

void attack(game_t *game, sfVector2i mouse_pos)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    if (game->turn == 0) {
        if (game->ind->ptr_skill->target == 0)
            target_enemy(game, temp2, mouse_pos);
        else
            target_ally(game, temp, mouse_pos);
    }
    else {
        if (game->ind->ptr_skill->target == 0)
            target_ally(game, temp, mouse_pos);
        else
            target_enemy(game, temp2, mouse_pos);
    }
}
