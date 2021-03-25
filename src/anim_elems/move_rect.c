/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void move_rect(sfIntRect *rect, int offset, int anim_nb)
{
    rect->left += offset;
    if (rect->left >= offset * anim_nb)
        rect->left = 0;
}

void bool_move_rect(sfIntRect *rect, int offset, int anim_nb, bool *boolean)
{
    rect->left += offset;
    if (rect->left >= offset * anim_nb) {
        rect->left = 0;
        *boolean = 0;
    }
}
