/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#ifndef MAP_H
#define MAP_H

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

#define PNJ_SPEAK_FIRST "Hello sir, It's going to be a lovely day."
#define PNJ_SPEAK_SECOND "How can i help you ?"
#define CHEST_SPEAK_FIRST "You find iron boots !"
#define CHEST_SPEAK_SECOND "It can be helpful to cross something .."

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
    bool already_open;
    bool chest_open;
    bool col_chest;
    size_t index;
    sfClock *clock_chest;
} chest_t;

typedef struct {
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f pnj_pos;
    bool interaction;
    bool exist;
    int last_dir;
    int speed_pnj;
} pnj_t;

typedef struct {
    sfRenderWindow *window;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f raccoon_pos;
    sfVector2f map_size;
    sfVector2f map_limit;
    obs_t obs;
    pnj_t pnj;
    chest_t chest;
    char **sentence;
    int speed;
    bool anim;
} raccoonmove_t;

typedef struct {
    sfClock *clock;
    char **sentence;
    char *save;
    size_t index;
    size_t str_index;
    int size_font;
    int delay;
    int color;
    sfVector2f pos;
    sfVector2f size_box;
} text_t;

text_t init_text(text_t text, raccoonmove_t *move);
void text_defil(char *str, text_t *text, sfRenderWindow *window);
raccoonmove_t init_struct_move(raccoonmove_t move, sfRenderWindow *window);
int change_map_back(raccoonmove_t *move);
int change_map_next(raccoonmove_t *move);
int init_obstacle(raccoonmove_t *move);
void free_obs(raccoonmove_t *move);
void display_change_first(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_second(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_up(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_down(raccoonmove_t *move, sfTexture *save, int o, int n);
char *my_itoa(int nb);
int create_col(int a, int b, raccoonmove_t *move, int *passed);
int ch_move(sfRenderWindow *window, raccoonmove_t *move);
void my_perso(sfRenderWindow *window, raccoonmove_t *move);
void display_next_map(raccoonmove_t *move);
void display_back_map(raccoonmove_t *move);
int pnj(raccoonmove_t *move);
int check_pnj_col(raccoonmove_t *move);
int map_event(raccoonmove_t *move, sfEvent event, int *passed, text_t *text);
int event_text(sfEvent event, char **str, text_t *text, raccoonmove_t *move);
int chest_open(raccoonmove_t *move, text_t *text);

#endif