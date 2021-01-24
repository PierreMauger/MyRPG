/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void take_turn(game_t *game)
{
    if (game->ind->ptr->next != NULL)
        game->ind->ptr = game->ind->ptr->next;
    else {
        if (game->turn == 0) {
            change_bool(&game->turn);
            game->ind->ptr = game->e_mons;
        }
        else {
            change_bool(&game->turn);
            game->ind->ptr = game->p_mons;
        }
    }
}

void init_turn_ind(game_t *game)
{
    game->ind = malloc(sizeof(indicator_t));
    game->ind->texture = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->ind->sprite = sfSprite_create();
    game->ind->rect = (sfIntRect){0, 0, 40, 80};
}

void draw_turn_ind(game_t *game)
{
    sfSprite_setOrigin(game->ind->sprite, sfSprite_getOrigin(game->ind->ptr->sprite));
    sfSprite_setPosition(game->ind->sprite, (sfVector2f){sfSprite_getPosition(game->ind->ptr->sprite).x + (game->ind->ptr->width - 40) / 2, sfSprite_getPosition(game->ind->ptr->sprite).y - 80});
    sfSprite_setTexture(game->ind->sprite, game->ind->texture, sfTrue);
    sfSprite_setTextureRect(game->ind->sprite, game->ind->rect);
    sfRenderWindow_drawSprite(game->window, game->ind->sprite, NULL);
}
