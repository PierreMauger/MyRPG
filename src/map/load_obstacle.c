/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int split_fill_obs(char *buff, int *i, char **stock)
{
    int z = 0;

    (*i)++;
    (*stock) = malloc(sizeof(char) * 30);
    for (; buff[*i] != 44 && buff[*i] != '\n'; z++) {
        (*stock)[z] = buff[*i];
        (*i)++;
    }
    (*stock)[z] = '\0';
    return (z);
}

static void get_batoi(raccoonmove_t *move, int *a, char *stock, int *h)
{
    char *less_space;
    int sp = 1;
    int new = 0;

    if (*h != 0) {
        less_space = malloc(sizeof(char) * bstrlen(stock));
        for (; stock[sp] != '\0'; sp++, new++)
            less_space[new] = stock[sp];
        less_space[new] = '\0';
        move->obs.obstacle[move->obs.index_obs][*a] = batoi(less_space);
        (*a)++;
        free(less_space);
    }
    free(stock);
    *h = 1;
}

static void fill_obstacle_tab(char *buff, raccoonmove_t *move, int *i)
{
    int a = 0;
    int h = 0;
    int z = 0;
    char *stock = NULL;

    while (buff[*i] != '}') {
        while (buff[*i] != ':' && buff[*i] != '}')
            (*i)++;
        if (buff[*i] == '}')
            break;
        z = split_fill_obs(buff, i, &stock);
        if (h == 0) {
            move->obs.type[move->obs.index_obs] = bstrdup(stock);
            move->obs.type[move->obs.index_obs][z] = '\0';
        }
        get_batoi(move, &a, stock, &h);
        z = 0;
    }
}

static void init_obstacle_split(char *buff, raccoonmove_t *move)
{
    int i = 0;
    int a = 0;

    for (; buff[i] != '\0'; i++)
        if (buff[i] == '}')
            a++;
    move->obs.obstacle = malloc(sizeof(int *) * a);
    move->obs.type = malloc(sizeof(char *) * a);
    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '{') {
            move->obs.obstacle[move->obs.index_obs] = malloc(sizeof(int) * 4);
            fill_obstacle_tab(buff, move, &i);
            move->obs.index_obs = move->obs.index_obs + 1;
        }
    }
}

int init_obstacle(raccoonmove_t *move)
{
    int fd = 0;
    int ret = 0;
    char buff[9000];

    fd = open(move->obs.fl_map_obstacle, O_RDWR);
    if (fd == -1)
        return (1);
    ret = read(fd, buff, 9000);
    if (ret == -1)
        return (1);
    buff[ret] = '\0';
    init_obstacle_split(buff, move);
    return (0);
}
