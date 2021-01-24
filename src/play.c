/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void atb_increase(game_t *game)
{
    mons_t *temp = game->p_mons;

    while (temp != NULL) {
        temp->atb_value += temp->speed;
        sfRectangleShape_setSize(temp->atb, (sfVector2f){temp->atb_value, 10});
        temp = temp->next;
    }
}

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                change_bool(&game->pause);
            if (game->event.key.code == sfKeyM)
                take_turn(game);
            if (game->event.key.code == sfKeyA)
                atb_increase(game);
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
        update_all(game);
        draw_all(game);
    }
}
