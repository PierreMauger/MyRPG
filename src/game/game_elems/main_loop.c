/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void loop_map(game_t *game)
{
    check_change_map(game->move);
    ch_move(GET_WINDOW, game->move);
    displ_all(GET_WINDOW, game->move, game->text);
}

void main_loop(game_t *game)
{
    inventory_t *inv = init_inventory(game);

    add_item_to_inv(inv, 1);
    add_item_to_inv(inv, 2);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        if (game->in_fight) {
            start_fight(game);
            fight_loop(game);
        }
        if (game->in_inv && game->set->pause == false)
            draw_inventory(game, inv);
        draw_quest_text(game);
        loop_map(game);
        sfRenderWindow_display(GET_WINDOW);
    }
    destroy_inv(inv);
}