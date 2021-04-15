/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void main_loop(game_t *game)
{
    menu_t *menu = main_menu(game);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        event_loop(game);
        menu_play(game, menu);
        if (game->in_fight) {
            start_fight(game);
            fight_loop(game);
        }
        sfRenderWindow_display(GET_WINDOW);
    }
}
