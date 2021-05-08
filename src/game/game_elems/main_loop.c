/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void loop_map(game_t *game)
{
    if (sfClock_getElapsedTime(game->move->map_clock).microseconds >= 10000) {
        if (game->in_inv == false) {
            check_change_map(game->move, game->text, game);
            ch_move(game->move);
            pnj(game->move);
            check_if_combat_start(game);
        }
        sfClock_restart(game->move->map_clock);
    }
    displ_all(GET_WINDOW, game->move, game->text, game);
}

bool is_item_in_inv(inventory_t *inv, char *name)
{
    list_t *temp = inv->list;

    for (; temp != NULL; temp = temp->next) {
        if (bstrcmp(temp->data->name, name) == 0)
            return true;
    }
    return false;
}

void check_items_acquierement(game_t *game, inventory_t *inv)
{
    if (game->move->item.sword == true &&
    is_item_in_inv(inv, "Basic Sword") == false)
        add_item_to_inv(inv, 5);
    if (game->move->item.boot == true &&
    is_item_in_inv(inv, "Soft Boots") == false)
        add_item_to_inv(inv, 3);
}

void main_loop(game_t *game)
{
    inventory_t *inv = init_inventory(game);
    int fight_res = 0;

    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        if (game->in_fight) {
            start_fight(game);
            fight_res = fight_loop(game);
        }
        if (game->in_inv && game->set->pause == false)
            draw_inventory(game, inv);
        draw_quest_text(game);
        loop_map(game);
        check_items_acquierement(game, inv);
        sfRenderWindow_display(GET_WINDOW);
    }
    destroy_inv(inv);
}
