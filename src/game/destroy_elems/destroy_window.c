/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_window(window_t *window)
{
    sfSprite_destroy(window->sprite);
    sfRenderWindow_destroy(window->window);
    sfRenderTexture_destroy(window->buffer);
    free(window);
}
