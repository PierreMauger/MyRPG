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
#include <stdbool.h>
#include "my.h"

typedef struct {
    char *fl_map_obstacle;
    int **obstacle;
    char **type;
    size_t index_obs;
    bool next_map;
    bool back_map;
    bool display_text_next;
    bool display_text_back;
} obs_t;

typedef struct {
    sfRenderWindow *window;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f dino_pos;
    sfVector2f map_size;
    sfVector2f map_limit;
    obs_t obs;
    int speed;
} dinomove_t;

dinomove_t init_struct_move(dinomove_t move, sfRenderWindow *window);
int change_map_back(dinomove_t *move);
int change_map_next(dinomove_t *move);
int init_obstacle(dinomove_t *move);
void free_obs(dinomove_t *move);
void display_change_first(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_second(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_up(dinomove_t *move, sfTexture *save, int o, int n);
void display_change_down(dinomove_t *move, sfTexture *save, int o, int n);
char *my_itoa(int nb);
int create_col(int a, int b, dinomove_t *move, int *passed);
int ch_move(sfRenderWindow *window, dinomove_t *move);
void my_perso(sfRenderWindow *window, dinomove_t *move);
void display_next_map(dinomove_t *move);
void display_back_map(dinomove_t *move);

#endif