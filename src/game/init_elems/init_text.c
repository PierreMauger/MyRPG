/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void my_first_init_text(game_t *game)
{
    game->text = malloc(sizeof(text_t) * 1);
    my_init_text(game->text);
}
