/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>
#include <game.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define PLAY_PATH "ressources/sprites/play_button.png"
#define EXIT_PATH "ressources/sprites/exit_button.png"
#define LOAD_PATH "ressources/sprites/load_button.png"

typedef struct button_s {
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfColor color;
    sfFloatRect f_rect;
    sfVector2f text_pos;
} button_t;

typedef struct game_object {
    int count_jump;
    sfSprite *sprite;
    sfVector2f vel;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect r;
    int speed;
} obj_t;

bool is_mouse_on_button(game_t *game, button_t *btn);

bool is_clicked(button_t *btn, game_t *game);

void destroy_button(button_t *btn);

button_t **list_button(int size_nbr);

button_t *create_button(sfVector2f pos, char *path, sfIntRect rect);

void draw_buttons(game_t *game, button_t **list);

void set_btn_pos(button_t *btn, sfVector2f pos);

void draw_button(game_t *game, button_t *btn);

void set_button_rect(button_t *btn, sfIntRect rect);

void set_button_color(button_t *btn, sfColor color);

//MENU_PROTO
void move_bg(sfSprite *spr, int spd, obj_t *obj);

obj_t *create_object(const char *path, sfVector2f pos, sfIntRect r);

obj_t **obj_n(int nbr_assets);

sfText *create_text_btn(sfText *txt, game_t *game, button_t *btn);

void display_menu(game_t *game, button_t **list);

void move_racoon_menu(game_t *game, sfIntRect rect, sfClock *clock,
sfSprite *sprite);

void display_shape_block(sfRectangleShape *shape, game_t *game, button_t **btn);

int menu_loop(game_t *game, button_t **btn);

//FONT_TEXTE_PROTO
sfText *init_font(sfText *txt, sfVector2f pos, char *font, char *text);

void set_size_font(sfText *txt, unsigned int size);

void set_color(sfText *txt, sfColor color);

void show_font(game_t *game, sfText *txt);

#endif
