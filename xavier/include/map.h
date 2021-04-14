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
    sfRenderWindow *window;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f dino_pos;
    sfVector2f map_size;
    sfVector2f map_limit;
    char *fl_map_obstacle;
    int **obstacle;
    char **type;
    size_t index_obs;
} dinomove_t;

dinomove_t init_struct_move(dinomove_t move);
int check_obs(dinomove_t *move, int dir);
int change_map_back(dinomove_t *move);
int change_map_next(dinomove_t *move);
int init_obstacle(dinomove_t *move);
void free_obs(dinomove_t *move);
void display_change_first(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_second(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_up(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_down(dinomove_t *move, sfTexture *save, int o, int n);

#endif