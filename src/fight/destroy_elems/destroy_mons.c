/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_mons_status(mons_status_t *status)
{
    free(status);
}

void destroy_mons_texture(mons_texture_t *texture)
{
    sfTexture_destroy(texture->texture);
    sfSprite_destroy(texture->sprite);
    free(texture);
}

void destroy_mons_stat(mons_stat_t *stat)
{
    sfRectangleShape_destroy(stat->hp);
    sfRectangleShape_destroy(stat->atb);
    free(stat);
}

void destroy_mons(mons_t *mons)
{
    mons_t *temp = NULL;

    while (mons != NULL) {
        temp = mons;
        destroy_mons_status(mons->status);
        destroy_mons_texture(mons->texture);
        destroy_mons_stat(mons->stat);
        destroy_skill(mons->skill);
        mons = mons->next;
        free(temp);
    }
}
