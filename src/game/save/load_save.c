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
    char *stock = (char *)parser(buff, "key", 1);

    if (bstrcmp(stock, "true") == 0)
        move->item.key = true;
    else
        move->item.key = false;
    stock = (char *)parser(buff, "boot", 1);
    if (bstrcmp(stock, "true") == 0) {
        move->item.boot = true;
        move->chest.already_open_second = true;
    }
    else
        move->item.boot = false;
    stock = (char *)parser(buff, "sword", 1);
    if (bstrcmp(stock, "true") == 0) {
        move->item.sword = true;
        move->chest.already_open_first = true;
    }
    else
        move->item.sword = false;
}

static int parsing_save(char *buff, raccoonmove_t *move)
{
    move->obs.fl_map_obstacle = (char *)parser(buff, "map", 1);
    move->raccoon_pos.x = (int)parser(buff, "raccoon_pos.x", 1);
    move->raccoon_pos.y = (int)parser(buff, "raccoon_pos.y", 1);
    move->pnj.pnj_pos.x = (int)parser(buff, "pnj_pos.x", 1);
    move->pnj.pnj_pos.y = (int)parser(buff, "pnj_pos.y", 1);
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
    parsing_save(buff, move);
    change_move(move);
    return (0);
}