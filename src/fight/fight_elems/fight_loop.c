/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static int check_end(game_t *game)
{
    if (game->e_mons == NULL) {
        get_xp(game->p_mons);
        game->in_fight = 0;
    }
    else if (game->p_mons == NULL) {
        game->in_fight = 0;
        return 1;
    }
    return 0;
}

int fight_loop(game_t *game)
{
    while (game->in_fight) {
        event_fight_loop(game);
        if (game->set->pause == false) {
            update_fight(game);
            draw_fight(game);
            if (check_end(game))
                return 1;
        }
    }
    return 0;
}
