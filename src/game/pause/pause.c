/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static int pause_event_pressed(int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ))
        (*i)--;
    if (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
        (*i)++;
    if (*i == -1)
        *i = 2;
    if (*i == 3)
        *i = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return (1);
    return (0);
}

static int split_pause(game_t *game, int *i)
{
    int ret = 0;

    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(GET_WINDOW);
        if (game->event.type == sfEvtKeyPressed)
            ret = pause_event_pressed(i);
        if (ret == 1)
            return (1);
    }
    return (0);
}

static int check_go_back(game_t *game, int i)
{
    if (i == 0)
        return (0);
    if (i == 1)
        save_elem(game);
    if (i == 2)
        sfRenderWindow_close(GET_WINDOW);
    return (0);
}

void my_pause(game_t *game)
{
    int i = 0;

    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        if (split_pause(game, &i) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            check_go_back(game, i);
            return;
        }
        sfRenderWindow_clear(GET_WINDOW, sfBlack);
        displ_all(GET_WINDOW, game->move, game->text, game);
        display_pause(game);
        display_arrow(game, &i);
        sfRenderWindow_display(GET_WINDOW);
    }
}
