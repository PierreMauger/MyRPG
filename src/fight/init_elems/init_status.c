/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_status_texture(game_t *game)
{
    game->status->texture = malloc(sizeof(sfTexture *) * status_nbr);
    game->status->texture[att_p] = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->status->texture[att_m] = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->status->texture[def_p] = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->status->texture[def_m] = sfTexture_createFromFile(GRASS_IMG, NULL);
}

void init_status_sprite(game_t *game)
{
    game->status->sprite = malloc(sizeof(sfSprite *) * status_nbr);
    game->status->sprite[att_p] = sfSprite_create();
    sfSprite_setTexture(game->status->sprite[att_p],
    game->status->texture[att_p], sfTrue);
    game->status->sprite[att_m] = sfSprite_create();
    sfSprite_setTexture(game->status->sprite[att_m],
    game->status->texture[att_m], sfTrue);
    game->status->sprite[def_p] = sfSprite_create();
    sfSprite_setTexture(game->status->sprite[def_p],
    game->status->texture[def_p], sfTrue);
    game->status->sprite[def_m] = sfSprite_create();
    sfSprite_setTexture(game->status->sprite[def_m],
    game->status->texture[def_m], sfTrue);
}

void init_status(game_t *game)
{
    game->status = malloc(sizeof(status_t));
    init_status_texture(game);
    init_status_sprite(game);
}
