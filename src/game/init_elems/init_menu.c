/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_menu(game_t *game)
{
    game->menu = malloc(sizeof(menu_t) * 1);
    game->menu->para = init_parallax(game->menu->para, 0);
    game->menu->paracpy = init_parallax(game->menu->paracpy, 1920);
}