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
    if (game->event.type == sfEvtMouseButtonPressed &&
    game->set->attack == true && game->set->in_anim != true) {
        choose_skill(game);
        set_attack(game);
    }
}

void event_fight_loop(game_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(GET_WINDOW);
    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        event_pause(game);
        if (!game->set->pause)
            event_click(game);
        if (game->event.type == sfEvtClosed) {
            game->in_fight = 0;
            sfRenderWindow_close(GET_WINDOW);
        }
    }
}
