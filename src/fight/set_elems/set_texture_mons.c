/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void set_texture_mons(mons_t *mons)
{
    sfSprite_setTexture(MONS_SPRITE(mons), mons->texture->texture, sfTrue);
    sfSprite_setTextureRect(MONS_SPRITE(mons), mons->texture->rect);
    sfSprite_setTexture(MONS_SPRITE_COLOR(mons),
    mons->texture->texture_color, sfTrue);
    sfSprite_setTextureRect(MONS_SPRITE_COLOR(mons), mons->texture->rect);
}
