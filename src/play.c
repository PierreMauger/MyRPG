/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                change_bool(&game->pause);
            if (game->event.key.code == sfKeyA)
                atb_increase(game, game->e_mons);
            if (game->event.key.code == sfKeyR)
                atb_reset(game);
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
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    draw_turn_ind(game);
    sfRenderWindow_display(game->window);
}

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == 0) {
        turn_loop(game);
        update_all(game);
        draw_all(game);
    }
}
