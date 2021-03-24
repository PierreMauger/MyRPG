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
        sfTexture_destroy(mons->texture_color);
        sfSprite_destroy(mons->sprite_color);
        sfRectangleShape_destroy(mons->hp);
        sfRectangleShape_destroy(mons->atb);
        destroy_skill(mons->skill);
        mons = mons->next;
    }
}
