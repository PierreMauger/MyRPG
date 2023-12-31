/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef GAME_H
#define GAME_H

#include "blib.h"
#include <button.h>
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
#define PTR_SKILL_ANIM_NB game->ind->ptr_skill->stat->nb_anim
#define PTR_SKILL_HIT_NB game->ind->ptr_skill->stat->nb_hit
#define PTR_SKILL_STATUS game->ind->ptr_skill->stat->status
#define PTR_SKILL_STATUS_TURN game->ind->ptr_skill->stat->status_turn

#define PTR_MONS_SPRITE game->ind->ptr_mons->texture->sprite
#define PTR_MONS_WIDTH game->ind->ptr_mons->texture->rect.width
#define PTR_MONS_RECT game->ind->ptr_mons->texture->rect

#define GET_WINDOW game->window->window
#define GET_CLOCK game->time->clock
#define GET_SECONDS game->time->seconds
#define GET_TOTAL_TIME game->time->total_time

#define STATUS_SPRITE game->status->sprite

#define CURR_ATT game->ind->curr_attack
#define ARR_RECT game->ind->arr->rect
#define ARR_ANIM_NB 2

#define GET_ATT(elem) (elem->stat->att * (1 + (bool)elem->status->att_p * 0.5 -\
(bool)elem->status->att_m * 0.5))
#define GET_DEF(elem) (elem->stat->def * (1 + (bool)elem->status->def_p * 0.5 -\
(bool)elem->status->def_m * 0.5))
#define GET_SPE(elem) (elem->stat->speed * (1 + (bool)elem->status->spe_p * 0.5\
- (bool)elem->status->spe_m * 0.5))

#define ANIM_TIME 0.3
#define GRASS_IMG "ressources/sprites/grass.png"
#define ATT_P_IMG "ressources/sprites/att_p.png"
#define ATT_M_IMG "ressources/sprites/att_m.png"
#define DEF_P_IMG "ressources/sprites/def_p.png"
#define DEF_M_IMG "ressources/sprites/def_m.png"
#define SPE_P_IMG "ressources/sprites/spe_p.png"
#define SPE_M_IMG "ressources/sprites/spe_m.png"
#define FONT "ressources/font.ttf"
#define SKILL_SHADER "ressources/shaders/skill_shader.frag"
#define TURN_SHADER "ressources/shaders/turn_shader.frag"
#define JSON_MONS "ressources/json/mons.json"
#define JSON_SKILL "ressources/json/skill.json"
#define RENDER_SKILL game->shader->render_skill
#define RENDER_TURN game->shader->render_turn

#define sfGrey (sfColor){128, 128, 128, 255}

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
    int nb_hit;
    int *aoe;
    int *atb_boost;
    int *status;
    int *status_turn;
    int passive;
    int ini_cd;
    int act_cd;
    int nb_anim;
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
    int att_p;
    int att_m;
    int def_p;
    int def_m;
    int spe_p;
    int spe_m;
} mons_status_t;

typedef struct {
    float speed;
    float att;
    float def;
    int max_hp;
    int curr_hp;
    float curr_atb;
    sfRectangleShape *hp;
    sfRectangleShape *atb;
} mons_stat_t;

typedef struct mons {
    mons_texture_t *texture;
    mons_stat_t *stat;
    mons_status_t *status;
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
    sfVector2f w_size;
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
    sfRenderStates render_skill;
    sfRenderStates render_turn;
    sfShader *skill;
    sfShader *turn;
} shader_t;

typedef enum {
    att_p,
    att_m,
    def_p,
    def_m,
    spe_p,
    spe_m,

    status_nbr
} status_list_t;

typedef struct {
    sfSprite **sprite;
    sfTexture **texture;
    sfText *text;
} status_t;

typedef struct menu_s {
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfMusic *music;
}menu_t;

typedef struct {
    window_t *window;
    time_elapsed_t *time;
    settings_t *set;
    sfEvent event;
    mons_t *p_mons;
    mons_t *e_mons;
    indicator_t *ind;
    status_t *status;
    sfVector2i mouse_pos;
    sfFont *font;
    shader_t *shader;
    bool in_fight;
} game_t;

//BUTTON_ELEMS
button_t **list_button(game_t *game, int size_nbr);
button_t *create_button(sfVector2f pos, char *path, sfIntRect rect);
bool is_mouse_on_button(game_t *game, button_t *btn);
void set_btn_pos(button_t *btn, sfVector2f pos);
void draw_button(game_t *game, button_t *btn);
void set_button_rect(button_t *btn, sfIntRect rect);
void set_button_color(button_t *btn, sfColor color);

//MENU_ELEMS
menu_t *main_menu(game_t *game);
void menu_play(game_t *game, menu_t *menu);
bool start_game(game_t *game, menu_t *menu, button_t *btn);

//ANIM_ELEMS
void animate(game_t *game);
void anim_all(game_t *game);
void anim_mons(game_t *game);
void move_rect(sfIntRect *rect, int offset, int nb_anim);
void bool_move_rect(sfIntRect *rect, int offset, int nb_anim, bool *boolean);

//DB_ELEMS
void init_mons_status(mons_t *elem);
void init_mons_texture(mons_t *elem, char *buffer, int i);
void init_mons_stat(mons_t *elem, char *buffer, int i);
void init_mons_skill(game_t *game, mons_t *elem, char *buffer, int id);
void put_in_mons_list(game_t *game, mons_t **mons, char *buffer, int id);
void init_skill_stat(skill_t *elem, char *buffer, int id);
void init_skill_texture(skill_t *elem, char *buffer, int id);
void init_skill_anim(skill_t *elem, char *buffer, int id);
void init_skill_desc(game_t *game, skill_t *elem, char *buffer, int id);
void put_in_skill_list(game_t *game, skill_t **skill, char *buffer, int id);

//DESTROY_ELEMS
void destroy_fight(game_t *game);
void destroy_turn_arrow(arrow_t *arr);
void destroy_turn_ind(indicator_t *ind);
void destroy_mons_status(mons_status_t *status);
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
void destroy_status_texture(sfTexture **texture);
void destroy_status_sprite(sfSprite **sprite);
void destroy_status(status_t *status);

//DRAW_ELEMS
void draw_fight(game_t *game);
void draw_single_attak_target(game_t *game, mons_t *mons);
void draw_attack_aoe(game_t *game);
void draw_attak_target(game_t *game);
void draw_turn_ind(game_t *game);
void draw_mons_sprites(game_t *game, mons_t *mons);
void draw_mons(game_t *game, mons_t *mons);
void draw_skill_desc(skill_t *temp, game_t *game, int x);
void draw_skill(game_t *game);
void draw_status_att(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos);
void draw_status_def(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos);
void draw_status_spe(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos);
void draw_status(game_t *game, mons_t *mons);

//FIGHT_ELEMS
void atb_increase(mons_t *team);
void atb_reset(game_t *game);
int check_atb(game_t *game);
mons_t *get_higher_atb(game_t *game);
int check_collide(game_t *game, mons_t *mons);
void atb_calc(game_t *game, mons_t *target);
void attack_hit(game_t *game, mons_t *target);
void attack_activation(game_t *game);
void cooldown_refresh(mons_t *target);
void cooldown_reduce(game_t *game);
void fight_loop(game_t *game);
mons_t *kill_func(game_t *game, mons_t *head);
void check_kill(game_t *game);
int has_passive(game_t *game);
void passive_action(game_t *game, mons_t *target);
void status_apply(game_t *game, mons_t *target);
void status_reduce_att(game_t *game);
void status_reduce_def(game_t *game);
void status_reduce(game_t *game);
void turn_loop(game_t *game);
void check_multi_hit(game_t *game);
void check_passive(game_t *game);
void check_turn(game_t *game);
void update_fight(game_t *game);

//GET_ELEMS
void event_pause(game_t *game);
void event_click(game_t *game);
void event_fight_loop(game_t *game);
int check_collide_skill(game_t *game, skill_t *skill);
void choose_skill(game_t *game);

//INIT_ELEMS
void init_fight(game_t *game);
void init_turn_arrow(game_t *game);
void init_turn_ind(game_t *game);
void init_mons_skill(game_t *game, mons_t *elem, char *buffer, int id);
void init_mons_pos(mons_t *mons, sfVector2f pos);
void init_all_pos(game_t *game);
void init_mons(game_t *game);
void init_shader(game_t *game);
void init_set(game_t *game);
void init_status_texture(game_t *game);
void init_status_sprite(game_t *game);
void init_status(game_t *game);
sfText *init_text(game_t *game, char *str, sfColor color);

//SET_ELEMS
void aoe_hit(game_t *game);
void set_attack_anim(game_t *game);
void set_attack_anim_pos(game_t *game, mons_t *target);
void multi_hit(game_t *game, mons_t *target);
void target_team(game_t *game);
void set_attack(game_t *game);
void set_texture_mons(mons_t *mons);

//PARSER
int *batoi_arr(char *src);
char *get_id(char *buffer, int id);
size_t parser(char *buffer, char *str, int id);

//INIT_ELEMS
void init_game(game_t *game);
void init_time(game_t *game);
sfRenderWindow *create_window(int width, int height);
void init_window(game_t *game);

//GAME_ELEMS
void main_loop(game_t *game);
void reset_fight(game_t *game);
void start_fight(game_t *game);

//GET_EVENT
void event_start_fight(game_t *game);
void event_loop(game_t *game);

//DESTROY_ELEMS
void destroy_game(game_t *game);
void destroy_time(time_elapsed_t *time);
void destroy_window(window_t *window);

#endif
