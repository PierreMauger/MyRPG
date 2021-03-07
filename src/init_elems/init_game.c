/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_game(game_t *game)
{
    game->w_size = (sfVideoMode){1920, 1080, 32};
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->clock = sfClock_create();
    game->state = 0;
    game->pause = false;
    game->turn = 0;
    game->attack = false;
    game->in_anim = false;
    game->p_mons = NULL;
    game->e_mons = NULL;
    game->mouse_pos = (sfVector2i){0, 0};
    game->font = sfFont_createFromFile("ressources/font");
    init_mons(game);
    init_turn_ind(game);
}
