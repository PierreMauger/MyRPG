/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void init_struct_move_split(raccoonmove_t *move)
{
    move->speed = 3;
    move->boot = false;
    move->pnj.speed_pnj = 2;
    move->obs.next_map = false;
    move->obs.back_map = false;
    move->obs.display_text_next = false;
    move->obs.display_text_back = false;
    move->chest.chest_open = false;
    move->chest.col_chest = false;
    move->pnj.exist = false;
    move->pnj.interaction = false;
    move->anim = false;
    move->chest.already_open_first = false;
    move->chest.already_open_second = false;
    move->key.col_key = false;
    move->key.taken = false;
}

void init_struct_move(raccoonmove_t *move, sfRenderWindow *window)
{
    move->map_size.x = 1440;
    move->map_size.y = 810;
    move->raccoon_pos.x = 555;
    move->raccoon_pos.y = 333;
    move->obs.fl_map_obstacle = MAP0;
    move->obs.index_obs = 0;
    move->my_texture = sfTexture_createFromFile("ressources/map/maison.jpg", NULL);
    move->my_sprite = sfSprite_create();
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->key.my_texture = sfTexture_createFromFile("ressources/sprites/key.png", NULL);
    move->key.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->key.my_sprite, move->key.my_texture, sfTrue);
    move->window = window;
    init_struct_move_split(move);
    if (init_obstacle(move) == 1)
        move->obs.index_obs = -1;
}