/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_turn_ind(game_t *game)
{
    game->ind = malloc(sizeof(indicator_t));
    game->ind->texture = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->ind->sprite = sfSprite_create();
    game->ind->rect = (sfIntRect){0, 0, 40, 80};
    game->ind->ptr = NULL;
}

void draw_turn_ind(game_t *game)
{
    sfSprite_setOrigin(game->ind->sprite, sfSprite_getOrigin(game->ind->ptr->sprite));
    sfSprite_setPosition(game->ind->sprite, (sfVector2f){sfSprite_getPosition(game->ind->ptr->sprite).x + (game->ind->ptr->width - 40) / 2, sfSprite_getPosition(game->ind->ptr->sprite).y - 80});
    sfSprite_setTexture(game->ind->sprite, game->ind->texture, sfTrue);
    sfSprite_setTextureRect(game->ind->sprite, game->ind->rect);
    sfRenderWindow_drawSprite(game->window, game->ind->sprite, NULL);
}

void destroy_turn_ind(indicator_t *ind)
{
    sfTexture_destroy(ind->texture);
    sfSprite_destroy(ind->sprite);
    free(ind);
}