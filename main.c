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
    sfIntRect rect = {0, 0, 156, 56};
    button_t **list = list_button(2);
    int menu_return = 0;

    list[0] = create_button((sfVector2f){320, 50}, "play_button.jpg", rect);
    list[1] = create_button((sfVector2f){320, 150}, "exit_button.png", rect);
    init_game(game);
    menu_return = menu_loop(game, list);
    if (menu_return != 2)
        main_loop(game);
    destroy_game(game);
    return 0;
}
