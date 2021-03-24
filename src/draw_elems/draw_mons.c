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
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->sprite, NULL);
        sfSprite_setTexture(temp->sprite_color, temp->texture_color, sfTrue);
        sfSprite_setTextureRect(temp->sprite_color, temp->rect);
        sfRenderWindow_drawSprite(game->window->window, temp->sprite_color, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, temp->hp, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, temp->atb, NULL);
        temp = temp->next;
    }
}
