/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int fill_obstacle_tab(char *buff, dinomove_t *move, int *i)
{
    int a = 0;
    int h = 0;
    int z = 0;
    char *stock;

    while (buff[*i] != '}') {
        while (buff[*i] != ':' && buff[*i] != '}')
            (*i)++;
        if (buff[*i] == '}') break;
        (*i)++, stock = malloc(sizeof(char) * 20);
        while (buff[*i] != ',')
            stock[z] = buff[*i], (*i)++, z++;
        stock[z] = '\0';
        if (h == 0)
            move->type[move->index_obs] = strdup(stock);
        else move->obstacle[move->index_obs][a] = atoi(stock), a++;
        free(stock), z = 0, h = 1;
    }
    return (0);
}

static int init_obstacle_split(char *buff, dinomove_t *move)
{
    int i = 0;
    int a = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '}')
            a++;
        i++;
    }
    move->obstacle = malloc(sizeof(int *) * a);
    move->type = malloc(sizeof(char *) * a);
    i = 0;
    while (buff[i] != '\0') {
        if (buff[i] == '{') {
            move->obstacle[move->index_obs] = malloc(sizeof(int) * 4);
            fill_obstacle_tab(buff, move, &i);
            move->index_obs++;
        }
        i++;
    }
    return (0);
}

int init_obstacle(dinomove_t *move)
{
    int fd = 0;
    int ret = 0;
    char buff[4096];

    fd = open(move->fl_map_obstacle, O_RDWR);
    if (fd == -1) return (1);
    ret = read(fd, buff, 4096);
    if (ret == -1) return (1);
    buff[ret] = '\0';
    init_obstacle_split(buff, move);
    return (0);
}

dinomove_t init_struct_move(dinomove_t move)
{
    move.map_size.x = 1440;
    move.map_size.y = 810;
    move.dino_pos.x = 0;
    move.dino_pos.y = 200;
    move.fl_map_obstacle = "json/map0.json";
    move.index_obs = 0;
    if (init_obstacle(&move) == 1)
        move.index_obs = -1;
    return (move);
}

int check_obs(dinomove_t *move, int dir)
{
    int i = 0;
    sfVector2f st = move->dino_pos;

    if (dir == 0) st.x -= 1.5;
    if (dir == 1) st.x += 1.5;
    if (dir == 2) st.y -= 1.5;
    if (dir == 3) st.y += 1.5;

    while (i != move->index_obs) {
        if (st.x >= move->obstacle[i][0] && st.x <= move->obstacle[i][1]) {
            if (st.y >= move->obstacle[i][2] && st.y <= move->obstacle[i][3]) {
                if (strcmp(move->type[i], " \"nextmap\"") == 0)
                    change_map_next(move);
                else if (strcmp(move->type[i], " \"backmap\"") == 0)
                    change_map_back(move);
                return (1);
            }
        }
        i++;
    }
    return (0);
}