/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include "button.h"

static int event_menu(game_t *game, button_t **list)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW);
    if (game->event.type == sfEvtMouseButtonPressed) {
        game->mouse_pos = sfMouse_getPositionRenderWindow(GET_WINDOW);
        if (is_mouse_on_button(game, list[0]))
            return 1;
        if (is_mouse_on_button(game, list[1]))
            return 2;
        if (is_mouse_on_button(game, list[2]))
            return 3;
    }
    return 0;
}

int menu_loop(game_t *game, button_t **list)
{
    int btn_return = 0;

    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event))
            btn_return = event_menu(game, list);
        if (btn_return)
            return btn_return;
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        display_menu(game, list);
        sfRenderWindow_display(GET_WINDOW);
    }
    return (0);
}
