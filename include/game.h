/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef GAME_H
#define GAME_H

#include "my.h"
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define MENU 0
#define PLAY 1
#define GAME_OVER 2
#define VICTORY 3
#define ANIME_TIME 0.3
#define DIRT_IMG "ressources/sprites/dirt.png"
#define GRASS_IMG "ressources/sprites/grass.png"
#define MONSTER_IMG "ressources/sprites/test_mult_texture.png"
#define MONSTER_IMG_COLOR "ressources/sprites/test_mult_texture_color.png"
#define MONSTER2_IMG "ressources/sprites/untitled.png"
#define MONSTER2_IMG_COLOR "ressources/sprites/untitled_color.png"

typedef struct {
    char name;
    int hp;
    int red;
    int green;
    int blue;
    char *sprite;
    char *sprite_color;
    int width;
    int height;
    int nb_anim;
    float speed;
} data_mons_t;

typedef struct mons {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture_color;
    sfSprite *sprite_color;
    int width;
    int height;
    int nb_anim;
    float speed;
    float atb_value;
    sfRectangleShape *atb;
    struct mons *next;
} mons_t;

typedef struct {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    mons_t *ptr;
} indicator_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    int state;
    int pause;
    int turn;
    mons_t *p_mons;
    mons_t *e_mons;
    indicator_t *ind;
} game_t;

        //game.c
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_game(game_t *game);
void main_loop(game_t *game);
void destroy_game(game_t *game);

        //play.c
void event_loop(game_t *game);
void update_all(game_t *game);
void draw_all(game_t *game);
void game_loop(game_t *game);

        //mons.c
void move_rect(sfIntRect *rect, int offset, int max_offset);
void init_mons(game_t *game);
void draw_mons(game_t *game, mons_t *mons);
void anim_mons(game_t *game);
void destroy_mons(mons_t *mons);

        //mons_list.c
int find_in_database(char name);
void put_in_mons_list(mons_t **mons, sfVector2f pos, char name);

        //turn.c
void take_turn(game_t *game);
void init_turn_ind(game_t *game);
void draw_turn_ind(game_t *game);
void destroy_turn_ind(indicator_t *ind);

#endif