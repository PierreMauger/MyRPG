/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_loop(game_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    while (sfRenderWindow_pollEvent(game->window, &game->event))
    {
        if (game->event.type == sfEvtKeyPressed)
            if (game->event.key.code == sfKeyP)
                change_bool(&game->pause);
        if (game->event.type == sfEvtMouseButtonPressed && game->attack == true
        && game->in_anim != true) {
            choose_skill(game);
            attack(game);
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void update_all(game_t *game)
{
    anim_all(game);
    if (game->in_anim == false)
        multi_hit(game, game->ind->target);
    if (game->in_anim == false)
        if (check_passive(game) == true)
            passive_action(game, game->ind->target);
    if (game->in_anim == false)
        turn_loop(game);
}

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == false) {
        update_all(game);
        draw_all(game);
    }
}
