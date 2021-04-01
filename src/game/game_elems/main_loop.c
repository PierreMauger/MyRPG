/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_start_fight(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        if (game->event.key.code == sfKeyF)
            game->in_fight = 1;
}

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        event_start_fight(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(GET_WINDOW);
    }
}

void reset_fight(game_t *game)
{
    char *buffer = bread_file(JSON_MONS, 20);
    mons_t *temp = game->p_mons;

    if (!buffer || bstrlen(buffer) < 10)
        return;
    game->e_mons = NULL;
    for (int i = 1; i < 4; i++)
        put_in_mons_list(game, &game->e_mons, buffer, i);
    while (temp != NULL) {
        MONS_CURR_ATB(temp) = 0;
        temp = temp->next;
    }
    init_all_pos(game);
    free(buffer);
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        if (game->in_fight) {
            reset_fight(game);
            fight_loop(game);
        }
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        sfRenderWindow_display(GET_WINDOW);
    }
}
