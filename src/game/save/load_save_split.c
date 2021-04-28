/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

int change_move(raccoonmove_t *move)
{
    int p = 0;

    if ((bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0) && p == 0) {
        move->my_texture = sfTexture_createFromFile(MAPMAISON, NULL);
        p++;
    }
    if ((bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0) && p == 0) {
        move->my_texture = sfTexture_createFromFile(MAPVILLAGE, NULL);
        p++;
    }
    if ((bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0) && p == 0) {
        move->my_texture = sfTexture_createFromFile(MAPPLAGE, NULL);
        p++;
    }
    if ((bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0) && p == 0)
        move->my_texture = sfTexture_createFromFile(MAPDONJON, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    free_obs(move);
    init_obstacle(move);
    return (0);
}

static void find_bool_split(char stock, raccoonmove_t *move, int i, char *buff)
{
    if (stock == 't') {
        move->boot = true;
        move->chest.already_open_second = true;
    }
    else
        move->boot = false;
    while (buff[i] != ':')
        i++;
    i += 2;
    stock = buff[i];
    if (stock == 't') {
        move->sword = true;
        move->chest.already_open_first = true;
    }
    else
        move->sword = false;
}

void find_bool(char *buff, raccoonmove_t *move, int i)
{
    char stock;

    while (buff[i] != ':')
        i++;
    i += 2;
    stock = buff[i];
    if (stock == 't')
        move->key.taken = true;
    else
        move->key.taken = false;
    while (buff[i] != ':')
        i++;
    i += 2;
    stock = buff[i];
    find_bool_split(stock, move, i, buff);
}