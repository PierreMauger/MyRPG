/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void loop_map(game_t *game, int *load)
{
    if (*load == 3) {
        *load = 0;
        load_save(game->move);
    }
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
    if (game->move->item.key == true &&
    is_item_in_inv(inv, "Key castle") == false)
        add_item_to_inv(inv, 4);
}

void check_winner(game_t *game, int fight_res)
{
    int p = 0;

    if (fight_res == 1) {
        my_loose(game);
        p++;
    }
    else if (bstrcmp(game->move->obs.fl_map_obstacle, MAP3) == 0) {
        my_victory(game);
        p++;
    }
    if (p == 0)
        check_map_sound(game->move);
}

void main_loop(game_t *game, int load)
{
    inventory_t *inv = init_inventory(game);
    int fight_res = 0;

    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        if (game->in_fight) {
            start_fight(game);
            fight_res = fight_loop(game);
            check_winner(game, fight_res);
        }
        if (draw_inventory(game, inv) == 1)
            return;
        draw_quest_text(game);
        loop_map(game, &load);
        check_items_acquierement(game, inv);
        stats_callback(inv, game);
        sfRenderWindow_display(GET_WINDOW);
    }
    destroy_inv(inv);
}
