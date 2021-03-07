/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_mons(game_t *game)
{
    sfVector2f p_pos = {200, 800};
    sfVector2f e_pos = {600, 400};
    char p_team[3] = "ddd";
    char e_team[3] = "abc";

    for (int i = 0; i < 3; i++) {
        put_in_mons_list(&game->p_mons, p_pos, p_team[i], game);
        put_in_mons_list(&game->e_mons, e_pos, e_team[i], game);
        p_pos.x += 200;
        e_pos.x += 350;
    }
}
