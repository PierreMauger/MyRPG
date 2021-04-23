/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int check_pnj_col(raccoonmove_t *move)
{
    int x = move->pnj.pnj_pos.x;
    int y = move->pnj.pnj_pos.y;

    if ((x >= move->raccoon_pos.x - 30 && x <= move->raccoon_pos.x + 30)
        && (y >= move->raccoon_pos.y - 30 && y <= move->raccoon_pos.y + 30)) {
        return (1);
    }
    return (0);
}