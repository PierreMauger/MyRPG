/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void split_check_obs(dinomove_t *move, int i)
{
    if (my_strcmp(move->obs.type[i], " \"nextmap\"") == 0)
        move->obs.display_text = true;
    if (my_strcmp(move->obs.type[i], " \"backmap\"") == 0)
        move->obs.display_text = true;
}

static int check_obs(dinomove_t *move, int dir)
{
    int i = 0;
    sfVector2f st = move->dino_pos;

    if (dir == 0) st.x -= 1.5;
    if (dir == 1) st.x += 1.5;
    if (dir == 2) st.y -= 1.5;
    if (dir == 3) st.y += 1.5;

    while (i != move->obs.index_obs) {
        if ((st.x >= move->obs.obstacle[i][0]
            && st.x <= move->obs.obstacle[i][1])
            && (st.y >= move->obs.obstacle[i][2]
            && st.y <= move->obs.obstacle[i][3])) {
            split_check_obs(move, i);
            return (1);
        }
        i++;
    }
    move->obs.display_text = false;
    return (0);
}

int ch_move(sfRenderWindow *window, dinomove_t *move)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (move->dino_pos.x >= 0 && check_obs(move, 0) == 0)
            move->dino_pos.x -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (move->dino_pos.x <= 1850 && check_obs(move, 1) == 0)
            move->dino_pos.x += 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (move->dino_pos.y >= 0 && check_obs(move, 2) == 0)
            move->dino_pos.y -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (move->dino_pos.y <= 950 && check_obs(move, 3) == 0)
            move->dino_pos.y += 1.5;
    }
}