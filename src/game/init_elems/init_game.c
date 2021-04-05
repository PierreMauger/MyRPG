/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_game(game_t *game)
{
    init_window(game);
    init_time(game);
    game->mouse_pos = (sfVector2i){0, 0};
    game->font = sfFont_createFromFile(FONT);
    game->in_fight = 0;
    init_fight(game);
    init_quest(game);
}
