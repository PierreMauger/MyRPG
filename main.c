/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include "button.h"

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    button_t *btn = malloc(sizeof(button_t));

    init_game(game);
    menu_loop(game, btn);
    main_loop(game);
    destroy_game(game);
    return 0;
}
