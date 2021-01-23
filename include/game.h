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

typedef struct p_mons {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    struct p_mons *next;
} p_mons_t;

typedef struct e_mons {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    struct e_mons *next;
} e_mons_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    int state;
    int pause;
    p_mons_t *mons;
} game_t;

        //game.c
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_game(game_t *game);
void main_loop(game_t *game);
void destroy_game(game_t *game);

        //play.c
int change_bool(int value);
void event_loop(game_t *game);
void update_all(game_t *game);
void draw_all(game_t *game);
void game_loop(game_t *game);

        //mons.c
void move_rect(sfIntRect *rect, int offset, int max_offset);
void put_in_mons_list(p_mons_t **mons, sfVector2f pos);
void init_mons(game_t *game);
void draw_mons(game_t *game);
void anim_mons(game_t *game);
void destroy_mons(p_mons_t *mons);

#endif