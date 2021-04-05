/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_fight(game_t *game)
{
    destroy_set(game->set);
    destroy_mons(game->p_mons);
    destroy_mons(game->e_mons);
    destroy_turn_ind(game->ind);
    destroy_shader(game->shader);
    destroy_status(game->status);
}
