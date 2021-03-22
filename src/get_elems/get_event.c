/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_pause(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        if (game->event.key.code == sfKeyP)
            game->pause = !game->pause;
}

void event_click(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed && game->attack == true
    && game->in_anim != true) {
        choose_skill(game);
        set_attack(game);
    }
}

void event_loop(game_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        event_pause(game);
        event_click(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}
