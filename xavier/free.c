/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void free_obs(dinomove_t *move)
{
    int i = 0;

    while (i != move->index_obs) {
        free(move->obstacle[i]);
        free(move->type[i]);
        i++;
    }
    free(move->obstacle);
    free(move->type);
    move->index_obs = 0;
}