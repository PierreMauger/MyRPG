/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include "button.h"

static void event_menu(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW);
}

int menu_loop(game_t *game, button_t *btn)
{
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event))
            event_menu(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        display_menu(game, btn);
        sfRenderWindow_display(GET_WINDOW);
    }
    return (0);
}