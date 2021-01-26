/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

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
