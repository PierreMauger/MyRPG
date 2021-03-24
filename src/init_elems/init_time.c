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
    game->time->clock = sfClock_create();
    game->time->seconds = 0;
}
