/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_single_mons(game_t *game, mons_t *mons, sfRenderStates *shader)
{
    sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE(mons), shader);
    sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE_COLOR(mons), shader);
}

void draw_mons_sprites(game_t *game, mons_t *mons)
{
    if (mons == game->ind->ptr_mons)
        draw_single_mons(game, mons, &RENDER_TURN);
    else if (mons == game->ind->target)
        draw_single_mons(game, mons, &RENDER_TARGET);
    else
        draw_single_mons(game, mons, NULL);
}

void draw_mons(game_t *game, mons_t *head)
{
    for (mons_t *temp = head; temp; temp = temp->next) {
        set_texture_mons(temp);
        draw_mons_sprites(game, temp);
        draw_status(game, temp);
        sfRenderWindow_drawRectangleShape(GET_WINDOW, MONS_HP(temp), NULL);
        sfRenderWindow_drawRectangleShape(GET_WINDOW, temp->stat->atb, NULL);
    }
}
