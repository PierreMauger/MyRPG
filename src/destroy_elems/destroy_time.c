/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_time(time_elapsed_t *time)
{
    sfClock_destroy(time->clock);
    free(time);
}
