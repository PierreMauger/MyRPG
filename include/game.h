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

#define MENU 0
#define PLAY 1
#define GAME_OVER 2
#define VICTORY 3
#define ANIME_TIME 0.3
#define CURR_ATT game->ind->curr_attack
#define DIRT_IMG "ressources/sprites/dirt.png"
#define GRASS_IMG "ressources/sprites/grass.png"
#define SLASH_IMG "ressources/sprites/slash_anim.png"
#define BONK_IMG "ressources/sprites/lol_anim.png"
#define SLIME_IMG "ressources/sprites/slime.png"
#define SLIME_IMG_COLOR "ressources/sprites/slime.png"
#define LANCER_IMG "ressources/sprites/lancer.png"
#define LANCER_IMG_COLOR "ressources/sprites/lancer_color.png"

typedef struct {
    char name;
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
    int red;
    int green;
    int blue;
    char *sprite;
    char *sprite_color;
    int width;
    int height;
    int nb_anim;
    float speed;
    char *skill;
} data_mons_t;

typedef struct skill {
    char name;
    int *coef;
    int *target;
    int nbr_hit;
    int *aoe;
    float *atb_boost;
    int passive;
    int ini_cd;
    int act_cd;
    int anim_nb;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect arect;
    sfTexture *atexture;
    sfSprite *asprite;
    sfTexture *dtexture;
    sfSprite *dsprite;
    sfText *text;
    sfText *cd_text;
    struct skill *next;
} skill_t;

typedef struct mons {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture_color;
    sfSprite *sprite_color;
    int width;
    int height;
    int nb_anim;
    int max_hp;
    int curr_hp;
    sfRectangleShape *hp;
    float speed;
    float atb_value;
    sfRectangleShape *atb;
    skill_t *skill;
    struct mons *next;
} mons_t;

typedef struct {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    mons_t *ptr_mons;
    skill_t *ptr_skill;
    mons_t *target;
    mons_t *team;
    sfText *damage;
    int curr_attack;
} indicator_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
} window_t;

typedef struct {
    sfClock *clock;
    float seconds;
} time_elapsed_t;

typedef struct {
    int state;
    bool pause;
    int turn;
    bool in_anim;
    bool attack;
} settings_t;

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
} game_t;

//ANIM_ELEMS
void anim_all(game_t *game);
void anim_mons(game_t *game);
void move_rect(sfIntRect *rect, int offset, int max_offset);
void single_move_rect(sfIntRect *rect, int offset, int max_offset, bool *boolean);

//DESTROY_ELEMS
void destroy_game(game_t *game);
void destroy_turn_ind(indicator_t *ind);
void destroy_mons(mons_t *mons);
void destroy_set(settings_t *set);
void destroy_skill(skill_t *skill);
void destroy_time(time_elapsed_t *time);
void destroy_window(window_t *window);

//DRAW_ELEMS
void draw_all(game_t *game);
void draw_single_attak_target(game_t *game);
void draw_attak_target(game_t *game);
void draw_turn_ind(game_t *game);
void draw_mons(game_t *game, mons_t *mons);
void draw_skill(game_t *game);

//GAME_ELEMS
void atb_increase(mons_t *team);
void atb_reset(game_t *game);
int check_atb(game_t *game);
mons_t *get_higher_atb(game_t *game);
void cooldown_reduce(game_t *game);
void kill_mons(game_t *game, mons_t *team, mons_t *curr_mons);
mons_t * kill_func(mons_t *head, mons_t *team, mons_t *curr_mons);
int check_passive(game_t *game);
void passive_action(game_t *game, mons_t *target);
void turn_loop(game_t *game);

//GET_ELEMS
void event_pause(game_t *game);
void event_click(game_t *game);
void event_loop(game_t *game);

//INIT_ELEMS
void init_game(game_t *game);
void init_turn_ind(game_t *game);
void init_mons(game_t *game);
void init_set(game_t *game);
void init_time(game_t *game);
void init_window(game_t *game);

//SET_ELEMS
void aoe_hit(game_t *game);
void set_attack_anim(game_t *game);
void set_attack_anim_pos(game_t *game, mons_t *target);
void multi_hit(game_t *game, mons_t *target);
void target_team(game_t *game);
void set_attack(game_t *game);

    //attack_hit.c
int check_collide(game_t *game, mons_t *mons);
void attack_hit(game_t *game, mons_t *team, mons_t *curr_mons);
void attack_activation(game_t *game);

    //game.c
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void main_loop(game_t *game);

    //mons_list.c
int find_in_mons_database(char name);
void put_in_mons_list(mons_t **mons, sfVector2f pos, char name, game_t *game);

    //play.c
void update_all(game_t *game);
void game_loop(game_t *game);

    //skill_list.c
int find_in_skill_database(char name);
void put_in_skill_list(skill_t **skill, char name, game_t *game);

    //skill.c
int check_collide_skill(game_t *game, skill_t *skill);
void choose_skill(game_t *game);

#endif
