/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

mons_t *kill_func(game_t *game, mons_t *head)
{
    mons_t *last = NULL;

    for (mons_t *act = head; act; act = act->next) {
        if (MONS_CURR_HP(act) == 0) {
            if (last == NULL)
                head = head->next;
            else
                last->next = act->next;
            destroy_mons_texture(act->texture);
            destroy_mons_stat(act->stat);
            destroy_skill(act->skill);
            free(act);
            game->ind->target = NULL;
            break;
        }
        last = act;
    }
    return head;
}

void check_kill(game_t *game)
{
    game->e_mons = kill_func(game, game->e_mons);
    game->p_mons = kill_func(game, game->p_mons);
}
