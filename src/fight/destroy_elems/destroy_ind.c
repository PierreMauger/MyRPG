/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_turn_arrow(arrow_t *arr)
{
    sfTexture_destroy(arr->texture);
    sfSprite_destroy(arr->sprite);
    free(arr);
}

void destroy_turn_ind(indicator_t *ind)
{
    destroy_turn_arrow(ind->arr);
    sfText_destroy(ind->damage);
    sfText_destroy(ind->att_name);
    free(ind);
}
