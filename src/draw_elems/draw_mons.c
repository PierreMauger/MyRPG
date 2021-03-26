/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_mons_sprites(game_t *game, mons_t *mons)
{
    if (mons == game->ind->ptr_mons) {
        sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE(mons),
        &TURN_RENDER);
        sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE_COLOR(mons),
        &TURN_RENDER);
    }
    else {
        sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE(mons), NULL);
        sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE_COLOR(mons), NULL);
    }
}

void draw_mons(game_t *game, mons_t *head)
{
    mons_t *temp = head;

    while (temp != NULL) {
        set_texture_mons(temp);
        draw_mons_sprites(game, temp);
        sfRenderWindow_drawRectangleShape(GET_WINDOW, MONS_HP(temp), NULL);
        sfRenderWindow_drawRectangleShape(GET_WINDOW, temp->stat->atb, NULL);
        temp = temp->next;
    }
}
