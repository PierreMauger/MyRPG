/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_fight(game_t *game)
{
    init_set(game);
    game->mouse_pos = (sfVector2i){0, 0};
    game->font = sfFont_createFromFile(FONT);
    init_mons(game);
    init_turn_ind(game);
    init_shader(game);
}
