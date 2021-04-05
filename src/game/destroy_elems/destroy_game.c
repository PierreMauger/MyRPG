/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_game(game_t *game)
{
    destroy_quest(game->quest, game->text);
    destroy_fight(game);
    destroy_time(game->time);
    destroy_window(game->window);
    sfFont_destroy(game->font_fight);
    sfFont_destroy(game->font);
    free(game);
}
