/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static void find_map(char *buff, raccoonmove_t *move, int *i)
{
    char *stock = malloc(sizeof(char) * 30);
    int a = 0;

    while (buff[*i] != ':')
        (*i)++;
    *i += 3;
    while (buff[*i] != '"') {
        stock[a] = buff[*i];
        (*i)++;
        a++;
    }
    stock[a] = '\0';
    move->obs.fl_map_obstacle = bstrdup(stock);
    free(stock);
}

static int find_pos_split(char *buff, raccoonmove_t *move, int *i)
{
    char *stock = malloc(sizeof(char) * 6);
    int a = 0;

    while (buff[*i] != ':')
        (*i)++;
    *i += 2;
    if (buff[*i] == ',')
        return (1);
    while (buff[*i] != '-') {
        stock[a] = buff[*i];
        (*i)++, a++;
    }
    (*i)++, a = 0;
    move->pnj.pnj_pos.x = batoi(stock);
    free(stock), stock = malloc(sizeof(char) * 6);
    while (buff[*i] != ',') {
        stock[a] = buff[*i];
        (*i)++, a++;
    }
    move->pnj.pnj_pos.y = batoi(stock), free(stock);
}

static void find_pos(char *buff, raccoonmove_t *move, int *i)
{
    char *stock = malloc(sizeof(char) * 6);
    int a = 0;

    *i += 2;
    while (buff[*i] != '-') {
        stock[a] = buff[*i];
        (*i)++, a++;
    }
    stock[a] = '\0';
    (*i)++, a = 0;
    move->raccoon_pos.x = batoi(stock);
    free(stock), stock = malloc(sizeof(char) * 6);
    while (buff[*i] != ',') {
        stock[a] = buff[*i];
        (*i)++, a++;
    }
    stock[a] = '\0';
    move->raccoon_pos.y = batoi(stock);
    free(stock);
    find_pos_split(buff, move, i);
}

static int parsing_save(char *buff, raccoonmove_t *move)
{
    int i = 0;

    while (buff[i] != '\0') {
        while (buff[i] != 'm')
            i++;
        find_map(buff, move, &i);
        while (buff[i] != ':')
            i++;
        find_pos(buff, move, &i);
        while (buff[i] != ':')
            i++;
        find_bool(buff, move, i);
        return (0);
    }
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