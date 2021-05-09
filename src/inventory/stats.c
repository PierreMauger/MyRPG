/*
** EPITECH PROJECT, 2021
** stats funcs
** File description:
** stats
*/

#include "game.h"

void stats_callback(inventory_t *inv, game_t *game)
{
    list_t *temp = inv->list;

    for (; temp != NULL; temp = temp->next) {
        if (temp->data->is_equiped == true && temp->data->is_active == false) {
            temp->data->is_active = true;
            game->p_mons->stat->att += (float)temp->data->dmg_buff;
            game->p_mons->stat->def += (float)temp->data->def_buff;
            game->p_mons->stat->att += (float)temp->data->speed_buff;
        }
        if (temp->data->is_equiped == false && temp->data->is_active == true) {
            temp->data->is_active = false;
            game->p_mons->stat->att -= (float)temp->data->dmg_buff;
            game->p_mons->stat->def -= (float)temp->data->def_buff;
            game->p_mons->stat->att -= (float)temp->data->speed_buff;
        }
    }
}