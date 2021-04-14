/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void load_map(dinomove_t *move, char *tex, char *map)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->fl_map_obstacle = map;
}

static int select_map_back(dinomove_t *move)
{
    int p = 0;

    if (strcmp(move->fl_map_obstacle, "json/map1.json") == 0 && p == 0) {
        load_map(move, "map/maison.jpg", "json/map0.json");
        p++;
    }
    if (strcmp(move->fl_map_obstacle, "json/map2.json") == 0 && p == 0) {
        load_map(move, "map/village.png", "json/map1.json");
        p++;
    }
    if (strcmp(move->fl_map_obstacle, "json/map3.json") == 0 && p == 0) {
        load_map(move, "map/plage.png", "json/map2.json");
        return (5);
    }
    return (0);
}

static void select_map_next(dinomove_t *move)
{
    int p = 0;

    if (strcmp(move->fl_map_obstacle, "json/map0.json") == 0 && p == 0) {
        load_map(move, "map/village.png", "json/map1.json");
        p++;
    }
    if (strcmp(move->fl_map_obstacle, "json/map1.json") == 0 && p == 0) {
        load_map(move, "map/plage.png", "json/map2.json");
        p++;
    }
    if (strcmp(move->fl_map_obstacle, "json/map2.json") == 0 && p == 0) {
        load_map(move, "map/donjon.jpg", "json/map3.json");
        p++;
    }
}

int change_map_next(dinomove_t *move)
{
    int o = 0;
    int n = 1440;
    sfTexture *save = move->my_texture;

    select_map_next(move);
    free_obs(move);
    init_obstacle(move);
    if (strcmp(move->fl_map_obstacle, "json/map3.json") == 0) {
        n = -720;
        display_change_up(move, save, o, n);
    }
    else
        display_change_first(move, save, o, n);
    return (0);
}

int change_map_back(dinomove_t *move)
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
    return (0);
}