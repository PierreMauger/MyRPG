/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#ifndef TEXT_H
#define TEXT_H

#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    sfVector2f dino_pos;
    sfVector2f map_size;
    sfVector2f map_limit;
    int **obstacle;
    char **type;
    size_t index_obs;
} dinomove_t;

dinomove_t init_struct_move(dinomove_t move);
int check_obs(dinomove_t *move, int dir);

#endif