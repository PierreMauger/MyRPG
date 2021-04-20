/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void main_loop(game_t *game)
{
    inventory_t *inv = init_inventory(game);

    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        if (game->in_fight) {
            start_fight(game);
            fight_loop(game);
        }
        if (game->in_inv)
            draw_inventory(game, inv);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        draw_quest_text(game);
        sfRenderWindow_display(GET_WINDOW);
    }
}
