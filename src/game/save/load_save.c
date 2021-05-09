/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static int change_move(raccoonmove_t *move)
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

static void find_bool_map(char *buff, raccoonmove_t *move)
{
    if (bstrcmp((char *)parser(buff, "door", 1), "true") == 0)
        move->item.door = true;
    else
        move->item.door = false;
    if (bstrcmp((char *)parser(buff, "key", 1), "true") == 0)
        move->item.key = true;
    else
        move->item.key = false;
    if (bstrcmp((char *)parser(buff, "boot", 1), "true") == 0) {
        move->item.boot = true;
        move->chest.already_open_second = true;
    }
    else
        move->item.boot = false;
    if (bstrcmp((char *)parser(buff, "sword", 1), "true") == 0) {
        move->item.sword = true;
        move->chest.already_open_first = true;
    }
    else
        move->item.sword = false;
}

static int parsing_save(char *buff, raccoonmove_t *move)
{
    int stock = 0;

    stock = (int)parser(buff, "raccoon_pos.x", 1);
    if (stock == -1)
        return (1);
    move->obs.fl_map_obstacle = (char *)parser(buff, "map", 1);
    move->raccoon_pos.x = stock;
    move->raccoon_pos.y = (int)parser(buff, "raccoon_pos.y", 1);
    stock = (int)parser(buff, "pnj_x", 1);
    if (stock != 0)
        move->pnj.pnj_pos.x = stock;
    stock = (int)parser(buff, "pnj_y", 1);
    if (stock != 0)
        move->pnj.pnj_pos.y = stock;
    find_bool_map(buff, move);
    return (0);
}

int load_save(raccoonmove_t *move)
{
    int fd = 0;
    int ret = 0;
    char buff[4096];

    fd = open("ressources/json/save.json", O_RDONLY);
    if (fd == -1)
        return (1);
    ret = read(fd, buff, 4096);
    buff[ret] = '\0';
    if (parsing_save(buff, move) == 0)
        change_move(move);
    music_dest(move, 1);
    check_map_sound(move);
    return (0);
}