/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static raccoonmove_t init_struct_move_split(raccoonmove_t move)
{
    move.speed = 2;
    move.pnj.speed_pnj = 1.5;
    move.obs.next_map = false;
    move.obs.back_map = false;
    move.obs.display_text_next = false;
    move.obs.display_text_back = false;
    move.chest.chest_open = false;
    move.chest.col_chest = false;
    move.pnj.exist = false;
    move.pnj.interaction = false;
    move.anim = false;
    move.chest.clock_chest = NULL;
    move.chest.already_open = false;
    return (move);
}

raccoonmove_t init_struct_move(raccoonmove_t move, sfRenderWindow *window)
{
    move.map_size.x = 1440;
    move.map_size.y = 810;
    move.raccoon_pos.x = 555;
    move.raccoon_pos.y = 333;
    move.obs.fl_map_obstacle = "json/map0.json";
    move.obs.index_obs = 0;
    move.my_texture = sfTexture_createFromFile("map/maison.jpg", NULL);
    move.my_sprite = sfSprite_create();
    sfSprite_setTexture(move.my_sprite, move.my_texture, sfTrue);
    move.window = window;
    move = init_struct_move_split(move);
    if (init_obstacle(&move) == 1)
        move.obs.index_obs = -1;
    return (move);
}

static void split_check_obs(raccoonmove_t *move, int i)
{
    if (my_strcmp(move->obs.type[i], " \"nextmap\"") == 0)
        move->obs.display_text_next = true;
    if (my_strcmp(move->obs.type[i], " \"backmap\"") == 0)
        move->obs.display_text_back = true;
    if (my_strcmp(move->obs.type[i], " \"chest\"") == 0) {
        move->chest.col_chest = true;
        move->chest.index = i;
    }
}

static int check_obs(raccoonmove_t *move, int dir)
{
    int i = 0;
    sfVector2f st = move->raccoon_pos;

    if (dir == 0) st.x -= move->speed;
    if (dir == 1) st.x += move->speed;
    if (dir == 2) st.y -= move->speed;
    if (dir == 3) st.y += move->speed;
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
    move->obs.display_text_next = false, move->obs.display_text_back = false;
    move->chest.col_chest = false;
    return (0);
}

int ch_move(sfRenderWindow *window, raccoonmove_t *move)
{
    if (move->anim == true)
        return (1);
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