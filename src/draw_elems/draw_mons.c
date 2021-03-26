/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_mons(game_t *game, mons_t *head)
{
    mons_t *temp = head;

    while (temp != NULL) {
        sfSprite_setTexture(MONS_SPRITE(temp), temp->texture->texture, sfTrue);
        sfSprite_setTextureRect(MONS_SPRITE(temp), temp->texture->rect);
        sfSprite_setTexture(MONS_SPRITE_COLOR(temp),
        temp->texture->texture_color, sfTrue);
        sfSprite_setTextureRect(MONS_SPRITE_COLOR(temp), temp->texture->rect);
        if (temp == game->ind->ptr_mons) {
            sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE(temp), &game->shader->render);
            sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE_COLOR(temp), &game->shader->render);
        }
        else {
            sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE(temp), NULL);
            sfRenderWindow_drawSprite(GET_WINDOW, MONS_SPRITE_COLOR(temp), NULL);
        }
        sfRenderWindow_drawRectangleShape(GET_WINDOW, MONS_HP(temp), NULL);
        sfRenderWindow_drawRectangleShape(GET_WINDOW, temp->stat->atb, NULL);
        temp = temp->next;
    }
}
