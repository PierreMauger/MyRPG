/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_time(game_t *game)
{
    game->time = malloc(sizeof(time_elapsed_t));
    GET_CLOCK = sfClock_create();
    GET_SECONDS = 0;
    GET_TOTAL_TIME = 0;
}
