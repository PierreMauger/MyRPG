/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_text(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed && game->in_dialog == 1
        && game->quest->start[game->qtext->str_index + 1] == NULL) {
        game->in_dialog = 0;
        game->qtext->index = 0, game->qtext->str_index = 0;
        return;
    }
    if (game->event.type == sfEvtMouseButtonPressed && game->in_dialog == 1
        && game->quest->start[game->qtext->str_index] != NULL) {
        game->qtext->str_index++, game->in_dialog = 0;
        game->qtext->index = 0;
    }
    if (game->event.type == sfEvtMouseButtonPressed && game->in_dialog == 0)
        game->in_dialog = 1;
}

void event_open_inv(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        if (game->event.key.code == sfKeyI)
            game->in_inv = true;
}

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->move->anim = true;
            my_pause(game);
            game->move->anim = false;
        }
        map_event(game->move, game->event, game->text);
        event_text(game);
        event_open_inv(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(GET_WINDOW);
    }
}
