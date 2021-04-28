/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void load_map(raccoonmove_t *move, char *tex, char *map)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->obs.fl_map_obstacle = map;
}

static int select_map_back(raccoonmove_t *move)
{
    int p = 0;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && p == 0) {
        load_map(move, "ressources/map/maison.jpg", MAP0);
        move->pnj.exist = false;
        move->raccoon_pos.x = 1300;
        move->raccoon_pos.y = 510;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && p == 0) {
        load_map(move, "ressources/map/village.png", MAP1);
        move->raccoon_pos.x = 1850;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0 && p == 0) {
        load_map(move, "ressources/map/plage.png", MAP2);
        move->raccoon_pos.x = 600;
        move->raccoon_pos.y = 5;
        return (5);
    }
    return (0);
}

static void select_map_next(raccoonmove_t *move)
{
    int p = 0;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0 && p == 0) {
        load_map(move, "ressources/map/village.png", MAP1);
        move->raccoon_pos.x = 5;
        move->raccoon_pos.y = 345;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && p == 0) {
        load_map(move, "ressources/map/plage.png", MAP2);
        move->raccoon_pos.x = 5;
        move->pnj.exist = false;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && p == 0) {
        load_map(move, "ressources/map/donjon.jpg", MAP3);
        move->raccoon_pos.x = 400;
        move->raccoon_pos.y = 915;
        p++;
    }
}

int change_map_next(raccoonmove_t *move)
{
    int n = 1440;
    sfTexture *save = move->my_texture;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0
        && move->key.taken == false) {
        move->obs.next_map = false;
        return (0);
    }
    select_map_next(move);
    free_obs(move);
    init_obstacle(move);
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0) {
        n = -720;
        display_change_up(move, save, 0, n);
    }
    else
        display_change_first(move, save, 0, n);
    move->obs.next_map = false;
    move->obs.display_text_next = false;
    return (0);
}

int change_map_back(raccoonmove_t *move)
{
    int o = 0;
    int n = -1440;
    int p = 0;
    sfTexture *save = move->my_texture;

    p = select_map_back(move);
    free_obs(move);
    init_obstacle(move);
    if (p == 5) {
        n = 720;
        display_change_down(move, save, o, n);
    }
    else
        display_change_second(move, save, o, n);
    move->obs.back_map = false;
    move->obs.display_text_back = false;
    return (0);
}