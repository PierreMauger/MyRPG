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
    game->ind->damage = sfText_create();
    sfText_setFont(game->ind->damage, game->font);
    sfText_setCharacterSize(game->ind->damage, 75);
    sfText_setColor(game->ind->damage, sfYellow);
    game->ind->rect = (sfIntRect){0, 0, 40, 80};
    game->ind->ptr_mons = NULL;
    game->ind->ptr_skill = NULL;
    game->ind->team = NULL;
    game->ind->target = NULL;
    CURR_ATT = 0;
}

void draw_turn_ind(game_t *game)
{
    sfSprite_setOrigin(game->ind->sprite, sfSprite_getOrigin(game->ind->ptr_mons->sprite));
    sfSprite_setPosition(game->ind->sprite, (sfVector2f){sfSprite_getPosition(game->ind->ptr_mons->sprite).x + (game->ind->ptr_mons->width - 40) / 2, sfSprite_getPosition(game->ind->ptr_mons->sprite).y - 80});
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
