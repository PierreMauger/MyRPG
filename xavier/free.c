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

    while (i != move->obs.index_obs) {
        free(move->obs.obstacle[i]);
        free(move->obs.type[i]);
        i++;
    }
    free(move->obs.obstacle);
    free(move->obs.type);
    move->obs.index_obs = 0;
}