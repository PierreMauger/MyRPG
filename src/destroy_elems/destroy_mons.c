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
        sfTexture_destroy(mons->mons_tex->texture);
        sfSprite_destroy(mons->mons_tex->sprite);
        sfTexture_destroy(mons->mons_tex->texture_color);
        sfSprite_destroy(mons->mons_tex->sprite_color);
        sfRectangleShape_destroy(mons->mons_stat->hp);
        sfRectangleShape_destroy(mons->mons_stat->atb);
        destroy_skill(mons->skill);
        mons = mons->next;
        free(temp);
    }
}
