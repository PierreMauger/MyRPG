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

void kill_mons(game_t *game, mons_t *mons_list, mons_t *curr_mons)
{
    mons_t *head = NULL;

    if (game->p_mons == mons_list) {
        head = game->p_mons;
        head = kill_func(head, mons_list, curr_mons);
        game->p_mons = head;
    }
    else {
        head = game->e_mons;
        head = kill_func(head, mons_list, curr_mons);
        game->e_mons = head;
    }
}

mons_t *kill_func(mons_t *head, mons_t *mons_list, mons_t *curr_mons)
{
    mons_t *last_mons = NULL;

    while (mons_list != NULL) {
        if (mons_list == curr_mons) {
            if (last_mons == NULL)
                head = head->next;
            else    
                last_mons->next = mons_list->next;
        }
        last_mons = mons_list;
        mons_list = mons_list->next;
    }
    return head;
}

void attack_hit(game_t *game, mons_t *mons_list, mons_t *curr_mons)
{
    curr_mons->curr_hp -= 30;
    if (curr_mons->curr_hp <= 0)
        kill_mons(game, mons_list, curr_mons);
    sfRectangleShape_setSize(curr_mons->hp, (sfVector2f){((float)curr_mons->curr_hp / (float)curr_mons->max_hp) * 100, 10});
    atb_reset(game);
    game->attack = 0;
}

void attack(game_t *game, sfVector2i mouse_pos)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    if (game->turn == 0) {
        while (temp2 != NULL) {
            if (check_collide(temp2, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
                attack_hit(game, game->e_mons, temp2);
            temp2 = temp2->next;
        }
    }
    else {
        while (temp != NULL) {
            if (check_collide(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
                attack_hit(game, game->p_mons, temp);
            temp = temp->next;
        }
    }
}