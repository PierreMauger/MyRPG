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
    while (buff[*i] != 44) {
        (*stock)[z] = buff[*i];
        (*i)++;
        z++;
    }
    (*stock)[z] = '\0';
    return (z);
}

static int fill_obstacle_tab(char *buff, raccoonmove_t *move, int *i)
{
    int a = 0;
    int h = 0;
    int z = 0;
    char *stock;

    while (buff[*i] != '}') {
        while (buff[*i] != ':' && buff[*i] != '}')
            (*i)++;
        if (buff[*i] == '}')
            break;
        z = split_fill_obs(buff, i, &stock);
        if (h == 0) {
            move->obs.type[move->obs.index_obs] = my_strdup(stock);
            move->obs.type[move->obs.index_obs][z] = '\0';
        }
        else
            move->obs.obstacle[move->obs.index_obs][a] = my_getnbr(stock) , a++;
        free(stock), z = 0, h = 1;
    }
    return (0);
}

static int init_obstacle_split(char *buff, raccoonmove_t *move)
{
    int i = 0;
    int a = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '}')
            a++;
        i++;
    }
    move->obs.obstacle = malloc(sizeof(int *) * a);
    move->obs.type = malloc(sizeof(char *) * a);
    i = 0;
    while (buff[i] != '\0') {
        if (buff[i] == '{') {
            move->obs.obstacle[move->obs.index_obs] = malloc(sizeof(int) * 4);
            fill_obstacle_tab(buff, move, &i);
            move->obs.index_obs = move->obs.index_obs + 1;
        }
        i++;
    }
    return (0);
}

int init_obstacle(raccoonmove_t *move)
{
    int fd = 0;
    int ret = 0;
    char buff[4096];

    fd = open(move->obs.fl_map_obstacle, O_RDWR);
    if (fd == -1) return (1);
    ret = read(fd, buff, 4096);
    if (ret == -1) return (1);
    buff[ret] = '\0';
    init_obstacle_split(buff, move);
    return (0);
}
