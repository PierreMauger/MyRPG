/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void split_check_obs(dinomove_t *move, int *p, int i)
{
    if (strcmp(move->type[i], " \"nextmap\"") == 0) {
        printf("yo\n");
        change_map_next(move);
        (*p)++;
    }
    else if (strcmp(move->type[i], " \"backmap\"") == 0) {
        change_map_back(move);
        (*p)++;
    }
}

int check_obs(dinomove_t *move, int dir)
{
    int i = 0;
    int p = 0;
    sfVector2f st = move->dino_pos;

    if (dir == 0) st.x -= 1.5;
    if (dir == 1) st.x += 1.5;
    if (dir == 2) st.y -= 1.5;
    if (dir == 3) st.y += 1.5;

    while (i != move->index_obs) {
        if ((st.x >= move->obstacle[i][0] && st.x <= move->obstacle[i][1])
            && (st.y >= move->obstacle[i][2] && st.y <= move->obstacle[i][3])) {
            split_check_obs(move, &p, i);
        }
        if (p == 1)
            return (1);
        i++;
    }
    return (0);
}