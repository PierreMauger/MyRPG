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
        sfSprite_setTexture(temp->texture->sprite, temp->texture->texture, sfTrue);
        sfSprite_setTextureRect(temp->texture->sprite, temp->texture->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->texture->sprite, NULL);
        sfSprite_setTexture(temp->texture->sprite_color, temp->texture->texture_color, sfTrue);
        sfSprite_setTextureRect(temp->texture->sprite_color, temp->texture->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->texture->sprite_color, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, MONS_HP(temp), NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, temp->stat->atb, NULL);
        temp = temp->next;
    }
}
