/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_fight(game_t *game)
{
    init_set(game);
    init_mons(game);
    init_turn_ind(game);
    init_shader(game);
}
