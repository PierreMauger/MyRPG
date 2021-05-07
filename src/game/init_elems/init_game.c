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
    game->font = sfFont_createFromFile(FONT_TEXT);
    game->font_fight = sfFont_createFromFile(FONT_FIGHT);
    game->in_fight = 0;
    game->in_dialog = 0;
    game->in_inv = false;
    init_menu(game);
    init_map(game);
    init_fight(game);
    init_quest(game);
    my_first_init_text(game);
}
