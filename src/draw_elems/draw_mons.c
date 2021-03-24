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
        sfSprite_setTexture(temp->mons_tex->sprite, temp->mons_tex->texture, sfTrue);
        sfSprite_setTextureRect(temp->mons_tex->sprite, temp->mons_tex->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->mons_tex->sprite, NULL);
        sfSprite_setTexture(temp->mons_tex->sprite_color, temp->mons_tex->texture_color, sfTrue);
        sfSprite_setTextureRect(temp->mons_tex->sprite_color, temp->mons_tex->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->mons_tex->sprite_color, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, MONS_HP(temp), NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, temp->mons_stat->atb, NULL);
        temp = temp->next;
    }
}
