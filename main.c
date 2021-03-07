/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_game(game);
    game->ind->ptr_mons = game->p_mons;
    main_loop(game);
    destroy_game(game);
    return 0;
}
