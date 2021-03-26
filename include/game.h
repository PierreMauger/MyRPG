/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef GAME_H
#define GAME_H

#include "my.h"
#include <stdbool.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define MONS_SPEED(elem) elem->stat->speed
#define MONS_MAX_HP(elem) elem->stat->max_hp
#define MONS_CURR_HP(elem) elem->stat->curr_hp
#define MONS_CURR_ATB(elem) elem->stat->curr_atb
#define MONS_HP(elem) elem->stat->hp
#define MONS_ATB(elem) elem->stat->atb

#define MONS_WIDTH(elem) elem->texture->rect.width
#define MONS_HEIGHT(elem) elem->texture->rect.height
#define MONS_SPRITE(elem) elem->texture->sprite
#define MONS_SPRITE_COLOR(elem) elem->texture->sprite_color

#define PTR_SKILL_ANIM_SPRITE game->ind->ptr_skill->anim->sprite
#define PTR_SKILL_ANIM_TEX game->ind->ptr_skill->anim->texture
#define PTR_SKILL_ANIM_RECT game->ind->ptr_skill->anim->rect
#define PTR_SKILL_ANIM_NB game->ind->ptr_skill->stat->anim_nb
#define PTR_SKILL_HIT_NB game->ind->ptr_skill->stat->nbr_hit

#define PTR_MONS_SPRITE game->ind->ptr_mons->texture->sprite
#define PTR_MONS_WIDTH game->ind->ptr_mons->texture->rect.width
#define PTR_MONS_RECT game->ind->ptr_mons->texture->rect

#define GET_WINDOW game->window->window
#define GET_CLOCK game->time->clock
#define GET_SECONDS game->time->seconds
#define GET_TOTAL_TIME game->time->total_time

#define CURR_ATT game->ind->curr_attack
#define ARR_RECT game->ind->arr->rect
#define ARR_ANIM_NB 2

#define MENU 0
#define PLAY 1
#define GAME_OVER 2
#define VICTORY 3
#define ANIME_TIME 0.3
#define DIRT_IMG "ressources/sprites/dirt.png"
#define GRASS_IMG "ressources/sprites/grass.png"
#define SLASH_IMG "ressources/sprites/slash_anim.png"
#define BONK_IMG "ressources/sprites/lol_anim.png"
#define SLIME_IMG "ressources/sprites/slime.png"
#define SLIME_IMG_COLOR "ressources/sprites/slime.png"
#define LANCER_IMG "ressources/sprites/lancer.png"
#define LANCER_IMG_COLOR "ressources/sprites/lancer_color.png"
#define FONT "ressources/font.ttf"
#define SKILL_SHADER "ressources/skill_shader.frag"
#define TURN_SHADER "ressources/turn_shader.frag"
#define TURN_RENDER game->shader->render

#define sfGrey (sfColor){128, 128, 128, 255}

typedef struct {
    char *name;
    int *coef;
    int nbr_hit;
    int *target;
    int *aoe;
    float *atb_boost;
    int passive;
    int cooldown;
    char *sprite;
    char *anim;
    int anim_x;
    int anim_y;
    int anim_nb;
    char *desc_img;
    char *desc;
} data_skill_t;

typedef struct {
    char name;
    int hp;
    char *sprite;
    char *sprite_color;
    int width;
    int height;
    int nb_anim;
    float speed;
    char **skill;
} data_mons_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
} skill_texture_t;

typedef struct {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} skill_anim_t;

typedef struct {
    char *name;
    int *coef;
    int *target;
    int nbr_hit;
    int *aoe;
    float *atb_boost;
    int passive;
    int ini_cd;
    int act_cd;
    int anim_nb;
} skill_stat_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfText *cd_text;
    sfText *name_text;
} skill_desc_t;

typedef struct skill {
    skill_texture_t *texture;
    skill_anim_t *anim;
    skill_stat_t *stat;
    skill_desc_t *desc;
    struct skill *next;
} skill_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture_color;
    sfSprite *sprite_color;
    sfIntRect rect;
    int nb_anim;
} mons_texture_t;

typedef struct {
    float speed;
    int max_hp;
    int curr_hp;
    float curr_atb;
    sfRectangleShape *hp;
    sfRectangleShape *atb;
} mons_stat_t;

typedef struct mons {
    mons_texture_t *texture;
    mons_stat_t *stat;
    skill_t *skill;
    struct mons *next;
} mons_t;

typedef struct {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} arrow_t;

typedef struct {
    arrow_t *arr;
    mons_t *ptr_mons;
    skill_t *ptr_skill;
    mons_t *target;
    mons_t *team;
    sfText *damage;
    sfText *att_name;
    int curr_attack;
} indicator_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
} window_t;

typedef struct {
    sfClock *clock;
    float seconds;
    float total_time;
} time_elapsed_t;

typedef struct {
    int state;
    bool pause;
    int turn;
    bool in_anim;
    bool attack;
} settings_t;

typedef struct {
    sfRenderStates render;
    sfShader *skill;
    sfShader *turn;
} shader_t;

typedef struct {
    window_t *window;
    time_elapsed_t *time;
    settings_t *set;
    sfEvent event;
    mons_t *p_mons;
    mons_t *e_mons;
    indicator_t *ind;
    sfVector2i mouse_pos;
    sfFont *font;
    shader_t *shader;
} game_t;

//ANIM_ELEMS
void animate(game_t *game);
void anim_all(game_t *game);
void anim_mons(game_t *game);
void move_rect(sfIntRect *rect, int offset, int anim_nb);
void bool_move_rect(sfIntRect *rect, int offset, int anim_nb, bool *boolean);

//DB_ELEMS
int find_in_mons_database(char name);
void init_mons_texture(mons_t *elem, sfVector2f pos, int i);
void init_mons_stat(mons_t *elem, sfVector2f pos, int i);
int find_in_skill_database(char *name);
void init_skill_stat(skill_t *elem, int i);
void init_skill_texture(skill_t *elem, int i);
void init_skill_anim(skill_t *elem, int i);
void init_skill_desc(skill_t *elem, game_t *game, int i);

//DESTROY_ELEMS
void destroy_game(game_t *game);
void destroy_turn_arrow(arrow_t *arr);
void destroy_turn_ind(indicator_t *ind);
void destroy_mons_texture(mons_texture_t *texture);
void destroy_mons_stat(mons_stat_t *stat);
void destroy_mons(mons_t *mons);
void destroy_set(settings_t *set);
void destroy_shader(shader_t *shader);
void destroy_skill_texture(skill_texture_t *texture);
void destroy_skill_anim(skill_anim_t *anim);
void destroy_skill_stat(skill_stat_t *stat);
void destroy_skill_desc(skill_desc_t *desc);
void destroy_skill(skill_t *skill);
void destroy_time(time_elapsed_t *time);
void destroy_window(window_t *window);

//DRAW_ELEMS
void draw_all(game_t *game);
void draw_single_attak_target(game_t *game);
void draw_attack_aoe(game_t *game);
void draw_attak_target(game_t *game);
void draw_turn_ind(game_t *game);
void draw_mons_sprites(game_t *game, mons_t *mons);
void draw_mons(game_t *game, mons_t *mons);
void draw_skill_desc(skill_t *temp, game_t *game, int x);
void draw_skill(game_t *game);

//GAME_ELEMS
void atb_increase(mons_t *team);
void atb_reset(game_t *game);
int check_atb(game_t *game);
mons_t *get_higher_atb(game_t *game);
void cooldown_reduce(game_t *game);
mons_t *kill_func(game_t *game, mons_t *head);
void check_kill(game_t *game);
int check_passive(game_t *game);
void passive_action(game_t *game, mons_t *target);
void turn_loop(game_t *game);

//GET_ELEMS
void event_pause(game_t *game);
void event_click(game_t *game);
void event_loop(game_t *game);
int check_collide_skill(game_t *game, skill_t *skill);
void choose_skill(game_t *game);

//INIT_ELEMS
void init_game(game_t *game);
void init_turn_arrow(game_t *game);
void init_turn_ind(game_t *game);
void put_in_mons_list(mons_t **mons, sfVector2f pos, char name, game_t *game);
void init_mons(game_t *game);
void init_shader(game_t *game);
void init_set(game_t *game);
sfText *init_text(game_t *game, char *string, sfColor color);
void init_time(game_t *game);
void init_window(game_t *game);
void put_in_skill_list(skill_t **skill, game_t *game, char *name);

//SET_ELEMS
void aoe_hit(game_t *game);
void set_attack_anim(game_t *game);
void set_attack_anim_pos(game_t *game, mons_t *target);
void multi_hit(game_t *game, mons_t *target);
void target_team(game_t *game);
void set_attack(game_t *game);
void set_texture_mons(mons_t *mons);

    //attack_hit.c
int check_collide(game_t *game, mons_t *mons);
void atb_calc(game_t *game, mons_t *curr_mons);
void attack_hit(game_t *game, mons_t *curr_mons);
void attack_activation(game_t *game);

    //game.c
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void main_loop(game_t *game);

    //play.c
void update_all(game_t *game);
void game_loop(game_t *game);

#endif
