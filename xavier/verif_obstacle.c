/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int split_check_obs(raccoonmove_t *move, int i)
{
    if (my_strcmp(move->obs.type[i], " \"lava\"") == 0 && move->boot == true)
        return (1);
    if (my_strcmp(move->obs.type[i], " \"key\"") == 0)
        move->key.col_key = true;
    if (my_strcmp(move->obs.type[i], " \"nextmap\"") == 0)
        move->obs.display_text_next = true;
    if (my_strcmp(move->obs.type[i], " \"backmap\"") == 0)
        move->obs.display_text_back = true;
    if (my_strcmp(move->obs.type[i], " \"chest\"") == 0) {
        if (my_strcmp(move->obs.fl_map_obstacle, "json/map0.json") == 0)
            move->chest.nb_chest = 1;
        if (my_strcmp(move->obs.fl_map_obstacle, "json/map1.json") == 0)
            move->chest.nb_chest = 2;
        move->chest.col_chest = true;
        move->chest.index = i;
    }
    return (0);
}

static sfVector2f save_move_obs(raccoonmove_t *move, int dir, sfVector2f st)
{
    st = move->raccoon_pos;
    if (dir == 0)
        st.x -= move->speed;
    if (dir == 1)
        st.x += move->speed;
    if (dir == 2)
        st.y -= move->speed;
    if (dir == 3)
        st.y += move->speed;
    return (st);
}

static int check_obs(raccoonmove_t *move, int dir)
{
    int i = 0;
    sfVector2f st = save_move_obs(move, dir, st);

    while (i != move->obs.index_obs) {
        if ((st.x >= move->obs.obstacle[i][0]
            && st.x <= move->obs.obstacle[i][1])
            && (st.y >= move->obs.obstacle[i][2]
            && st.y <= move->obs.obstacle[i][3])) {
            if (split_check_obs(move, i) != 1)
                return (1);
        }
        i++;
    }
    move->obs.display_text_next = false;
    move->obs.display_text_back = false;
    move->chest.col_chest = false;
    return (0);
}

void ch_move(raccoonmove_t *move)
{
    if (move->anim == true)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (move->raccoon_pos.x >= 0 && check_obs(move, 0) == 0)
            move->raccoon_pos.x -= move->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)
        || sfKeyboard_isKeyPressed(sfKeyD)) {
        if (move->raccoon_pos.x <= 1850 && check_obs(move, 1) == 0)
            move->raccoon_pos.x += move->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (move->raccoon_pos.y >= 0 && check_obs(move, 2) == 0)
            move->raccoon_pos.y -= move->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS)) {
        if (move->raccoon_pos.y <= 950 && check_obs(move, 3) == 0)
            move->raccoon_pos.y += move->speed;
    }
}
