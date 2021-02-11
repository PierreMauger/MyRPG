/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void move_rect(sfIntRect *rect, int offset, int max_offset)
{
    rect->left += offset;
    if (rect->left >= max_offset)
        rect->left = 0;
}

void single_move_rect(sfIntRect *rect, int offset, int max_offset, int *boolean)
{
    rect->left += offset;
    if (rect->left >= max_offset) {
        rect->left = 0;
        *boolean = 0;
    }
}
