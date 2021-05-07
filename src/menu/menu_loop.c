/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void event_menu(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW);
}

int menu_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event))
            event_menu(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        sfRenderWindow_display(GET_WINDOW);
    }
    return (0);
}