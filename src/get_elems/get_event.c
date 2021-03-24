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
            game->set->pause = !game->set->pause;
}

void event_click(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed && game->set->attack == true
    && game->set->in_anim != true) {
        choose_skill(game);
        set_attack(game);
    }
}

void event_loop(game_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
    while (sfRenderWindow_pollEvent(game->window->window, &game->event)) {
        event_pause(game);
        event_click(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->window);
    }
}
