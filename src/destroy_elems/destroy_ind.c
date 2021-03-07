/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_turn_ind(indicator_t *ind)
{
    sfTexture_destroy(ind->texture);
    sfSprite_destroy(ind->sprite);
    free(ind);
}
