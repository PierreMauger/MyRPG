/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void free_obs(raccoonmove_t *move)
{
    for (int i = 0; i != (int)move->obs.index_obs; i++) {
        free(move->obs.obstacle[i]);
        free(move->obs.type[i]);
    }
    free(move->obs.obstacle);
    free(move->obs.type);
    move->obs.index_obs = 0;
}
