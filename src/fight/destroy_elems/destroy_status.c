/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_status_texture(sfTexture **texture)
{
    for (int i = 0; i < status_nbr; i++)
        sfTexture_destroy(texture[i]);
    free(texture);
}

void destroy_status_sprite(sfSprite **sprite)
{
    for (int i = 0; i < status_nbr; i++)
        sfSprite_destroy(sprite[i]);
    free(sprite);
}

void destroy_status(status_t *status)
{
    destroy_status_texture(status->texture);
    destroy_status_sprite(status->sprite);
    sfText_destroy(status->text);
    free(status);
}
