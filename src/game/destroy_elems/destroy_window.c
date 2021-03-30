/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_window(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    free(window);
}
