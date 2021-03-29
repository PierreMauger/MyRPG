/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void move_rect(sfIntRect *rect, int offset, int nb_anim)
{
    rect->left += offset;
    if (rect->left >= offset * nb_anim)
        rect->left = 0;
}

void bool_move_rect(sfIntRect *rect, int offset, int nb_anim, bool *boolean)
{
    rect->left += offset;
    if (rect->left >= offset * nb_anim) {
        rect->left = 0;
        *boolean = 0;
    }
}
