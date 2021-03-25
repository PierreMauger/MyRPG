/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void kill_mons(game_t *game, mons_t *team, mons_t *curr_mons)
{
    mons_t *head = NULL;

    if (game->p_mons == team) {
        head = game->p_mons;
        head = kill_func(head, team, curr_mons);
        game->p_mons = head;
    }
    else {
        head = game->e_mons;
        head = kill_func(head, team, curr_mons);
        game->e_mons = head;
    }
}

mons_t *kill_func(mons_t *head, mons_t *team, mons_t *curr_mons)
{
    mons_t *last_mons = NULL;

    while (team != NULL) {
        if (team == curr_mons) {
            if (last_mons == NULL)
                head = head->next;
            else
                last_mons->next = team->next;
            destroy_mons_texture(team->texture);
            destroy_mons_stat(team->stat);
            destroy_skill(team->skill);
            free(team);
            break;
        }
        last_mons = team;
        team = team->next;
    }
    return head;
}
