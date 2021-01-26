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
            if (game->event.key.code == sfKeyR)
                my_printf("%d\n", game->ind->ptr_skill->coef);
        }
        if (game->event.type == sfEvtMouseButtonPressed && game->attack == 1) {
            choose_skill(game, sfMouse_getPositionRenderWindow(game->window));
            attack(game, sfMouse_getPositionRenderWindow(game->window));
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void update_all(game_t *game)
{
    anim_mons(game);
    turn_loop(game);
}

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window, sfWhite);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    draw_turn_ind(game);
    draw_skill(game);
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
