/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_all_pos(game_t *game)
{
    sfVector2f p_pos = {200, 600};
    sfVector2f e_pos = {600, 300};

    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        init_mons_pos(temp, p_pos);
        p_pos.x += 250;
    }
    for (mons_t *temp = game->e_mons; temp; temp = temp->next) {
        init_mons_pos(temp, e_pos);
        e_pos.x += 250;
    }
}

void init_mons(game_t *game)
{
    char *buffer = bread_file(JSON_MONS, 20);

    if (!buffer || bstrlen(buffer) < 10)
        return;
    game->p_mons = NULL;
    for (int i = 1; i < 4; i++)
        put_in_mons_list(game, &game->p_mons, buffer, i);
    free(buffer);
}
