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
    init_mons(game);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    main_loop(game);
    destroy_game(game);
    return 0;
}
