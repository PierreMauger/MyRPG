/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void split_create_col(int fd, int a, int b, int *passed)
{
    if (*passed == 0) {
        write(fd, "\n{\n\t\"type\": \"default\",\n", 23);
        write(fd, "\t\"hor.x\": ", 10);
        write(fd, my_itoa(a), my_strlen(my_itoa(a)));
    }
    if (*passed == 1) {
        write(fd, ",\n\t\"hor.y\": ", 12);
        write(fd, my_itoa(a), my_strlen(my_itoa(a)));
        write(fd, ",", 1);
    }
    if (*passed == 2) {
        write(fd, "\n\t\"ver.x\": ", 11);
        write(fd, my_itoa(b), my_strlen(my_itoa(b)));
        write(fd, ",", 1);
    }
    if (*passed == 3) {
        write(fd, "\n\t\"ver.y\": ", 11);
        write(fd, my_itoa(b), my_strlen(my_itoa(b)));
        write(fd, ",\n},", 4);
    }
}

int create_col(int a, int b, dinomove_t *move, int *passed)
{
    int fd = 0;
    char buff[4096];

    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        free_obs(move);
        init_obstacle(move);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        fd = open(move->obs.fl_map_obstacle,
        O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1)
            return (-2);
        read(fd, buff, 4096);
        split_create_col(fd, a, b, passed);
        (*passed)++;
        if (*passed == 4)
            *passed = 0;
        close (fd);
    }
    return (0);
}