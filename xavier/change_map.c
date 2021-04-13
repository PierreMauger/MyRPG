/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void zero_map(dinomove_t *move, char *tex, char *map)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->dino_pos.x = 0;
    move->fl_map_obstacle = map;
}

static void second_map(dinomove_t *move, char *tex, char *map)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->dino_pos.x = 0;
    move->fl_map_obstacle = map;
}

static void first_map(dinomove_t *move, char *tex, char *map)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->dino_pos.x = 0;
    move->fl_map_obstacle = map;
}

int change_map_next(dinomove_t *move)
{
    int o = 0;
    int n = 1440;
    sfTexture *save = move->my_texture;

    if (strcmp(move->fl_map_obstacle, "json/map0.json") == 0)
        zero_map(move, "map/village.png", "json/map1.json");
    else if (strcmp(move->fl_map_obstacle, "json/map1.json") == 0)
        first_map(move, "map/plage.png", "json/map2.json");
    free_obs(move);
    init_obstacle(move);
    if (strcmp(move->fl_map_obstacle, "json/map3.json") == 0)
        display_change_up(move, save, o, n);
    else
        display_change_first(move, save, o, n);
    return (0);
}

int change_map_back(dinomove_t *move)
{
    int o = 0;
    int n = -1440;
    sfTexture *save = move->my_texture;

    if (strcmp(move->fl_map_obstacle, "json/map1.json") == 0)
        first_map(move, "map/maison.jpg", "json/map0.json");
    else if (strcmp(move->fl_map_obstacle, "json/map2.json") == 0)
        second_map(move, "map/village.png", "json/map1.json");
    free_obs(move);
    init_obstacle(move);
    if (strcmp(move->fl_map_obstacle, "json.map3.json") == 0)
        display_change_down(move, save, o, n);
    display_change_second(move, save, o, n);
    return (0);
}