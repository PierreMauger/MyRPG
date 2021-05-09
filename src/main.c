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
    sfIntRect rect = {0, 0, 200, 75};
    button_t **list = list_button(2);
    int menu_return = 0;

    list[0] = create_button((sfVector2f){320, 50}, PLAY_PATH, rect);
    list[1] = create_button((sfVector2f){320, 200}, EXIT_PATH, rect);
    init_game(game);
    menu_return = menu_loop(game, list);
    if (menu_return != 2)
        main_loop(game);
    destroy_game(game);
    return 0;
}
