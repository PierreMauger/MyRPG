/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_mons(mons_t *mons)
{
    while (mons != NULL) {
        sfTexture_destroy(mons->texture);
        sfSprite_destroy(mons->sprite);
        mons = mons->next;
    }
}
