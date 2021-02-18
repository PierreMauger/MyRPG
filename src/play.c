/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void event_loop(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;

    while (sfRenderWindow_pollEvent(game->window, &game->event))
    {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                change_bool(&game->pause);
            if (game->event.key.code == sfKeyM)
                my_put_nbr(game->ind->ptr_skill->ini_cd);
            if (game->event.key.code == sfKeyL) {
                while (temp != NULL) {
                    my_put_nbr(temp->act_cd);
                    temp = temp->next;
                }
            }
        }
        if (game->event.type == sfEvtMouseButtonPressed && game->attack == 1 && game->in_anim != 1) {
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
    if (game->in_anim == 0) {
        if (check_passive(game) == 1)
            passive_action(game, game->ind->team, game->ind->target);
        turn_loop(game);
    }
}

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    draw_turn_ind(game);
    draw_skill(game);
    draw_attak_target(game);
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
