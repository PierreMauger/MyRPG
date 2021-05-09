/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef GAME_H
#define GAME_H

#include "blib.h"
#include "map.h"
#include <stdbool.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define MONS_LEVEL(elem) elem->stat->level
#define MONS_XP(elem) elem->stat->xp
#define MONS_SPEED(elem) elem->stat->speed
#define MONS_ATT(elem) elem->stat->att
#define MONS_DEF(elem) elem->stat->def
#define MONS_MAX_HP(elem) elem->stat->max_hp
#define MONS_CURR_HP(elem) elem->stat->curr_hp
#define MONS_CURR_ATB(elem) elem->stat->curr_atb
#define MONS_HP(elem) elem->stat->hp
#define MONS_ATB(elem) elem->stat->atb

#define MONS_WIDTH(elem) elem->texture->rect.width
#define MONS_HEIGHT(elem) elem->texture->rect.height
#define MONS_SPRITE(elem) elem->texture->sprite

#define PTR_SKILL_ANIM_SPRITE game->ind->ptr_skill->anim->sprite
#define PTR_SKILL_ANIM_TEX game->ind->ptr_skill->anim->texture
#define PTR_SKILL_ANIM_RECT game->ind->ptr_skill->anim->rect
#define PTR_SKILL_ANIM_NB game->ind->ptr_skill->stat->nb_anim
#define PTR_SKILL_STATUS game->ind->ptr_skill->stat->status
#define PTR_SKILL_STATUS_TURN game->ind->ptr_skill->stat->status_turn

#define PTR_MONS_SPRITE game->ind->ptr_mons->texture->sprite
#define PTR_MONS_WIDTH game->ind->ptr_mons->texture->rect.width
#define PTR_MONS_RECT game->ind->ptr_mons->texture->rect

#define GET_WINDOW game->window->window
#define GET_BUFFER game->window->buffer
#define GET_CLOCK game->time->clock
#define GET_SECONDS game->time->seconds
#define GET_TOTAL_TIME game->time->total_time

#define STATUS_SPRITE game->status->sprite

#define CURR_ATT game->ind->curr_attack
#define ARR_RECT game->ind->arr->rect
#define ARR_ANIM_NB 3

#define GET_ATT(elem) (elem->stat->att * (1 + (bool)elem->status->att_p\
* 0.5 - (bool)elem->status->att_m * 0.5))
#define GET_DEF(elem) (elem->stat->def * (1 + (bool)elem->status->def_p\
* 0.5 - (bool)elem->status->def_m * 0.5))
#define GET_SPE(elem) (elem->stat->speed * (1 + (bool)elem->status->spe_p\
* 0.5 - (bool)elem->status->spe_m * 0.5))

#define BAR_SIZE (sfVector2f){100, 10}

#define ANIM_TIME 0.3
#define ARROW_IMG "ressources/sprites/arrow.png"
#define ATT_P_IMG "ressources/sprites/att_p.png"
#define ATT_M_IMG "ressources/sprites/att_m.png"
#define DEF_P_IMG "ressources/sprites/def_p.png"
#define DEF_M_IMG "ressources/sprites/def_m.png"
#define SPE_P_IMG "ressources/sprites/spe_p.png"
#define SPE_M_IMG "ressources/sprites/spe_m.png"
#define FONT_TEXT "ressources/absender.ttf"
#define FONT_FIGHT "ressources/font.ttf"
#define SKILL_SHADER "ressources/shaders/skill_shader.frag"
#define TURN_SHADER "ressources/shaders/turn_shader.frag"
#define TARGET_SHADER "ressources/shaders/target_shader.frag"
#define SNOW_SHADER "ressources/shaders/snow_shader.frag"
#define RAIN_SHADER "ressources/shaders/rain_shader.frag"
#define JSON_MONS "ressources/json/mons.json"
#define JSON_SKILL "ressources/json/skill.json"
#define JSON_QUEST "ressources/json/quest.json"
#define JSON_ITEMS "ressources/json/items.json"
#define RENDER_SKILL game->shader->render_skill
#define RENDER_TURN game->shader->render_turn
#define RENDER_TARGET game->shader->render_target
#define RENDER_SNOW game->shader->render_snow
#define RENDER_RAIN game->shader->render_rain

#define sfGrey (sfColor){128, 128, 128, 255}

// More defines for paths
#define INV_PATH "ressources/sprites/inv.png"
#define SELEC_PATH "ressources/sprites/select.png"
#define EQU_PATH "ressources/sprites/equiped.png"
#define PROMPT_PATH "ressources/sprites/prompt.png"

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
    int xp;
    int level;
    sfRectangleShape *hp;
    sfRectangleShape *atb;
} mons_stat_t;

typedef struct mons {
    mons_texture_t *texture;
    mons_stat_t *stat;
    mons_status_t *status;
    skill_t *skill;
    int id;
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
    sfRenderTexture *buffer;
    sfTexture *tex;
    sfSprite *sprite;
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
    sfRectangleShape *rect;
    sfText *text;
    int delay;
    char *save;
    size_t index;
    size_t str_index;
    int size_font;
    sfVector2f pos;
    sfVector2f size;
} quest_text_t;

typedef struct {
    sfVector2f final_pos;
    char **start;
    char **end;
} quest_t;

typedef struct {
    sfRenderStates render_skill;
    sfRenderStates render_turn;
    sfRenderStates render_target;
    sfRenderStates render_snow;
    sfRenderStates render_rain;
    sfShader *skill;
    sfShader *turn;
    sfShader *target;
    sfShader *snow;
    sfShader *rain;
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

typedef struct {
    float sky;
    float mont;
    float tree;
    float grass;
} speed_t;

typedef struct {
    sfVector2f sky;
    sfVector2f mont;
    sfVector2f tree;
    sfVector2f grass;
} pos_parallax_t;

typedef struct {
    sfTexture *sky;
    sfSprite *sprite_sky;
    sfTexture *mont;
    sfSprite *sprite_mont;
    sfTexture *grass;
    sfSprite *sprite_grass;
    sfTexture *tree;
    sfSprite *sprite_tree;
    speed_t speed;
    pos_parallax_t pos_para;
} parallax_t;

typedef struct {
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfMusic *music;
    bool music_playing;
    parallax_t *para;
    parallax_t *paracpy;
} menu_t;

typedef struct {
    window_t *window;
    time_elapsed_t *time;
    sfEvent event;
    settings_t *set;
    mons_t *p_mons;
    mons_t *e_mons;
    indicator_t *ind;
    status_t *status;
    shader_t *shader;
    sfVector2i mouse_pos;
    sfFont *font;
    sfFont *font_fight;
    quest_t *quest;
    quest_text_t *qtext;
    bool in_fight;
    bool in_dialog;
    bool in_inv;
    raccoonmove_t *move;
    text_t *text;
    menu_t *menu;
} game_t;

typedef struct item {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    bool is_in_inventory;
    bool is_equiped;
    bool is_active;
    int index;
    char *name;
    char *description;
    int dmg_buff;
    int def_buff;
    int speed_buff;
} item_t;

typedef struct list {
    item_t *data;
    struct list *next;
} list_t;

typedef struct inventory {
    sfSprite *invsprite;
    sfTexture *invtexture;
    sfSprite *selecsprite;
    sfTexture *selectexture;
    sfSprite *equipedsprite;
    sfTexture *equipedtexture;
    sfSprite *promptsprite;
    sfTexture *prompttexture;
    sfText *prompttext;
    sfVector2u pos;
    short selected;
    bool prompt;
    list_t *list;
} inventory_t;

// LL funcs
void draw_list(sfRenderWindow *w, list_t *items);
void list_stack(list_t **head, item_t *data);
void list_destroy(list_t *head);
void list_remove(list_t **head, int index);

// Inventory funcs
int get_item_index(list_t *inv);
inventory_t *init_inventory(game_t *game);
void add_item_to_inv(inventory_t *inv, int item_id);
item_t *create_item(int id);
int draw_inventory(game_t *game, inventory_t *inv);
int poll_inv_events(game_t *game, inventory_t *inv);
void set_selec_pos(inventory_t *inv);
void draw_equiped(game_t *game, inventory_t *inv);
void destroy_inv(inventory_t *inv);
void init_prompt_text(inventory_t *inv, game_t *game);
void display_prompt(inventory_t *inv, game_t *game);
item_t *get_selected_item(inventory_t *inv);
void set_string(inventory_t *inv, item_t *item, int id);
void stats_callback(inventory_t *inv, game_t *game);

//MENU_ELEMS
menu_t *main_menu(game_t *game);
void menu_play(game_t *game, menu_t *menu);
bool start_game(game_t *game, menu_t *menu);
parallax_t *init_parallax(parallax_t *parallax, int pos_max);
void display_parallax(game_t *game);
void init_menu(game_t *game);

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
void change_background(game_t *game);

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
int fight_loop(game_t *game);
mons_t *kill_func(game_t *game, mons_t *head);
void check_kill(game_t *game);
void get_xp(mons_t *mons);
char *level_up(char *buffer, mons_t *mons);
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
void check_if_combat_start(game_t *game);

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
void init_mons_pos(mons_t *mons, sfVector2f pos, float size);
void init_all_pos(game_t *game);
void init_mons(game_t *game);
sfRenderStates init_renderstate(sfShader *shader);
void init_shader(game_t *game);
void init_set(game_t *game);
void init_status_texture(game_t *game);
void init_status_sprite(game_t *game);
void init_status(game_t *game);
void init_map(game_t *game);
void my_first_init_text(game_t *game);
sfText *init_text(game_t *game, char *str, sfColor color);

//SET_ELEMS
void aoe_hit(game_t *game);
void set_attack_anim(game_t *game);
void set_attack_anim_pos(game_t *game, mons_t *target);
void multi_hit(game_t *game, mons_t *target);
void target_team(game_t *game);
void set_attack(game_t *game);
void set_auto_attack(game_t *game);
void set_texture_mons(mons_t *mons);

//PARSER
int *batoi_arr(char *src);
char *get_id(char *buffer, int id);
size_t parser_array(char *buffer, int i);
size_t parser(char *buffer, char *str, int id);
char *parser_write(char *buffer, char *name, char *new_name, int id);

//INIT_ELEMS
void init_game(game_t *game);
void init_time(game_t *game);
sfRenderWindow *create_window(int width, int height);
void init_window(game_t *game);
sfRectangleShape *init_rectangle(sfVector2f size, sfColor color, int center_x);

//GAME_ELEMS
void loop_map(game_t *game, int *load);
void main_loop(game_t *game, int menu_return);
void reset_fight(game_t *game);
void start_fight(game_t *game);

//GET_EVENT
void event_loop(game_t *game);

// PAUSE_ELEMS
void my_pause(game_t *game);
void display_arrow(game_t *game, int *i);
void display_pause(game_t *game);

// SAVE_ELEMS
int save_elem(game_t *game);
int load_save(raccoonmove_t *move);

//DESTROY_ELEMS
void destroy_game(game_t *game);
void destroy_time(time_elapsed_t *time);
void destroy_window(window_t *window);
void destroy_menu(menu_t *menu);

void init_quest(game_t *game);
void draw_quest_text(game_t *game);
void destroy_quest(quest_t *quest, quest_text_t *quest_text);

void displ_all(sfRenderWindow *window, raccoonmove_t *move, text_t *text,
game_t *game);

void change_map_back(raccoonmove_t *move, game_t *game);
void change_map_next(raccoonmove_t *move, text_t *text, game_t *game);
void check_change_map(raccoonmove_t *move, text_t *text, game_t *game);

void my_victory(game_t *game);
void my_loose(game_t *game);

#endif
