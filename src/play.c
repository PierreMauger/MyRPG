/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void take_turn(game_t *game)
{
    if (game->curr_mons->next != NULL)
        game->curr_mons = game->curr_mons->next;
    else {
        if (game->turn == 0) {
            change_bool(&game->turn);
            game->curr_mons = game->e_mons;
        }
        else {
            change_bool(&game->turn);
            game->curr_mons = game->p_mons;
        }
    }
}

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                change_bool(&game->pause);
            if (game->event.key.code == sfKeyO)
                printf("%f %f\n", sfSprite_getPosition(game->curr_mons->sprite).x, sfSprite_getPosition(game->curr_mons->sprite).y);
            if (game->event.key.code == sfKeyM)
                take_turn(game);
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void update_all(game_t *game)
{
    anim_mons(game);
}

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window, sfYellow);
    draw_mons(game);
    sfRenderWindow_display(game->window);
}

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == 0) {
        update_all(game);
        draw_all(game);
    }
}
