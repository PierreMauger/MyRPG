/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_fight(game_t *game)
{
    sfRenderWindow_clear(GET_WINDOW, sfBlack);
    sfRenderTexture_clear(GET_BUFFER, sfBlack);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    if (game->set->in_anim == false && game->set->attack == true) {
        draw_turn_ind(game);
        draw_skill(game);
    }
    draw_attak_target(game);
    game->window->tex = (sfTexture *)sfRenderTexture_getTexture(GET_BUFFER);
    sfSprite_setTexture(game->window->sprite, game->window->tex, sfFalse);
    sfRenderWindow_drawSprite(GET_WINDOW, game->window->sprite, &RENDER_SNOW);
    sfRenderTexture_display(GET_BUFFER);
    sfRenderWindow_display(GET_WINDOW);
}
