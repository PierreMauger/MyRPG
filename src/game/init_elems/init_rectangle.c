/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfRectangleShape *init_rectangle(sfVector2f size, sfColor color, int center_x)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOrigin(rect, (sfVector2f){(center_x + size.x) / 2, 0});
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}
