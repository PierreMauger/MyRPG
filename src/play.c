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

void anim_all(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        anim_mons(game);
        move_rect(&game->ind->rect, 40, 80);
        if (game->in_anim == true) {
            single_move_rect(&game->ind->ptr_skill->arect, 80, 320, &game->in_anim);
            if (game->in_anim == false)
                attack_activation(game);
        }
        sfClock_restart(game->clock);
    }
}

void update_all(game_t *game)
{
    anim_all(game);
    if (game->in_anim == false) {
        if (check_passive(game) == true)
            passive_action(game, game->ind->target);
    }
    if (game->in_anim == false)
        turn_loop(game);
}

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    draw_turn_ind(game);
    if (game->in_anim == false && game->attack == true)
        draw_skill(game);
    draw_attak_target(game);
    sfRenderWindow_display(game->window);
}

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == false) {
        update_all(game);
        draw_all(game);
    }
}
