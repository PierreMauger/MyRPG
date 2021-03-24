/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_set(game_t *game)
{
    game->set = malloc(sizeof(settings_t));
    game->set->state = 0;
    game->set->pause = false;
    game->set->turn = 0;
    game->set->attack = false;
    game->set->in_anim = false;
}
