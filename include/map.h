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
#include "blib.h"

// ressources define
#define MAP0 "ressources/json/map0.json"
#define MAP1 "ressources/json/map1.json"
#define MAP2 "ressources/json/map2.json"
#define MAP3 "ressources/json/map3.json"
#define RACCOON "ressources/sprites/raccoon_spritesheet.png"
#define RCBOSS "ressources/sprites/raccoonbagar.png"
#define KEY "ressources/sprites/key.png"
#define SWORD "ressources/sprites/ecosword.png"
#define MAPMAISON "ressources/map/maison.jpg"
#define MAPPLAGE "ressources/map/plage.jpg"
#define MAPVILLAGE "ressources/map/village.png"
#define MAPDONJON "ressources/map/donjon.jpg"
#define PNJ "ressources/sprites/farm_spritesheet.png"
#define PNJRUN "ressources/sprites/farmrun_spritesheet.png"
#define FIGHT_MAP1 "ressources/map/fight_forest.jpg"
#define FIGHT_MAP2 "ressources/map/beach_fight.jpg"
#define MAP_OBS move->obs.fl_map_obstacle

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
    sfTexture *my_texture;
    sfSprite *my_sprite;
    bool already_open_first;
    bool already_open_second;
    bool chest_open;
    bool col_chest;
    size_t index;
    int nb_chest;
} chest_t;

typedef struct {
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f pnj_pos;
    bool interaction;
    bool exist;
    int last_dir;
    int speed_pnj;
    bool door_open;
    bool idle;
} pnj_t;

typedef struct {
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f pos;
    bool interaction;
    bool last;
    bool dead;
} enemy_t;

typedef struct {
    int nb_enemy;
    int who_enemy;
} enemy_info_t;

typedef struct {
    sfTexture *my_texture;
    sfSprite *my_sprite;
    bool col_key;
} mykey_t;

typedef struct {
    bool boot;
    bool sword;
    bool key;
    bool door;
} itemmap_t;

typedef struct {
    sfClock *anim_clock;
    sfClock *npc_clock;
    sfClock *enemy_clock;
    int anim_ene;
    int anim_rac;
    int anim_npc;
    int anim_npc_run;
    int speed_anim;
    bool idle;
} anim_rac_t;

typedef struct {
    sfMusic *chest;
    sfMusic *rain;
    sfMusic *snow;
    sfMusic *theme;
} music_t;

typedef struct {
    sfRenderWindow *window;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfTexture *fight_map_texture;
    sfSprite *fight_map_sprite;
    sfTexture *my_texture_rac;
    sfSprite *my_sprite_rac;
    sfVector2f raccoon_pos;
    sfClock *map_clock;
    obs_t obs;
    pnj_t pnj;
    enemy_t **enemy;
    enemy_info_t enemy_info;
    chest_t chest;
    mykey_t key;
    itemmap_t item;
    anim_rac_t animrac;
    music_t music;
    char **sentence;
    int speed;
    bool climat_change;
    bool anim;
} raccoonmove_t;

typedef struct {
    sfClock *clock;
    bool display;
    char *save;
    size_t index;
    size_t str_index;
    int size_font;
    int delay;
    int color;
    int color2;
    sfVector2f pos;
    sfVector2f size_box;
} text_t;

void my_init_text(text_t *text);
void text_defil(char *str, text_t *text, sfRenderWindow *window);
void init_struct_move(raccoonmove_t *move, sfRenderWindow *window);
int init_obstacle(raccoonmove_t *move);
void free_obs(raccoonmove_t *move);
void display_change_first(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_second(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_up(raccoonmove_t *move, sfTexture *save, int o, int n);
void display_change_down(raccoonmove_t *move, sfTexture *save, int o, int n);
char *my_itoa(int nb);
void ch_move(raccoonmove_t *move);
void my_perso(sfRenderWindow *window, raccoonmove_t *move);
void display_use(raccoonmove_t *move);
int pnj(raccoonmove_t *move);
int check_pnj_col(raccoonmove_t *move);
void map_event(raccoonmove_t *move, sfEvent event, text_t *text);
void my_event_text(sfEvent event, char **str, text_t *text, raccoonmove_t *mov);
void chest_open(raccoonmove_t *move);
int create_sentence_chest(raccoonmove_t *move, text_t *text);
void create_sentence_pnj(raccoonmove_t *move, text_t *text);
void display_mykey(raccoonmove_t *move, int x, int y);
void display_pnj(raccoonmove_t *move);
int load_save(raccoonmove_t *move);
void check_got_sword(raccoonmove_t *move, text_t *text);
void climat_map(raccoonmove_t *move, text_t *text);
int enemy(raccoonmove_t *move);
int init_enemy(raccoonmove_t *move);
void check_if_combat(raccoonmove_t *move);
char *get_text_open(char *filepath);
size_t parser(char *buffer, char *str, int id);
int check_use_now(raccoonmove_t *move);
void change_anim_npc(raccoonmove_t *move, int p);
void change_anim_npc_run(raccoonmove_t *move, int p);
void create_mus(char *filepath, sfMusic **music, int loop);
void music_dest(raccoonmove_t *move, int i);
void init_music(raccoonmove_t *move);
void check_map_sound(raccoonmove_t *move);
void check_map_sound_go(raccoonmove_t *move);

#endif
