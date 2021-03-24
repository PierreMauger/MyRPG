/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_mons(mons_t *mons)
{
    mons_t *temp = NULL;

    while (mons != NULL) {
        temp = mons;
        sfTexture_destroy(mons->texture->texture);
        sfSprite_destroy(mons->texture->sprite);
        sfTexture_destroy(mons->texture->texture_color);
        sfSprite_destroy(mons->texture->sprite_color);
        sfRectangleShape_destroy(MONS_HP(mons));
        sfRectangleShape_destroy(mons->stat->atb);
        destroy_skill(mons->skill);
        mons = mons->next;
        free(temp);
    }
}
