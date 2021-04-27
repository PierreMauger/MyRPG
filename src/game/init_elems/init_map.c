/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_map(game_t *game)
{
    game->move = malloc(sizeof(raccoonmove_t) * 1);
    init_struct_move(game->move, GET_WINDOW);
}