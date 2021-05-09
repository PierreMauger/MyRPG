/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"
#include "game.h"

static void load_map(raccoonmove_t *move, char *tex, char *map, game_t *game)
{
    move->my_texture = sfTexture_createFromFile(tex, NULL);
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->obs.fl_map_obstacle = map;
    change_background(game);
}

static int select_map_back(raccoonmove_t *move, game_t *game, int p)
{
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && p == 0) {
        load_map(move, "ressources/map/maison.jpg", MAP0, game);
        move->pnj.exist = false;
        move->raccoon_pos.x = 1300;
        move->raccoon_pos.y = 510;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && p == 0) {
        load_map(move, "ressources/map/village.png", MAP1, game);
        move->raccoon_pos.x = 1850;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0 && p == 0) {
        load_map(move, "ressources/map/plage.jpg", MAP2, game);
        move->raccoon_pos.x = 600;
        move->raccoon_pos.y = 5;
        return (5);
    }
    return (0);
}

static void select_map_next(raccoonmove_t *move, text_t *text, game_t *game)
{
    int p = 0;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0 && p == 0) {
        load_map(move, "ressources/map/village.png", MAP1, game);
        move->raccoon_pos.x = 5;
        move->raccoon_pos.y = 345;
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && p == 0) {
        load_map(move, "ressources/map/plage.jpg", MAP2, game);
        move->raccoon_pos.x = 5;
        climat_map(move, text);
        p++;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && p == 0) {
        load_map(move, "ressources/map/donjon.jpg", MAP3, game);
        move->raccoon_pos.x = 400;
        move->raccoon_pos.y = 900;
        p++;
    }
}

void change_map_next(raccoonmove_t *move, text_t *text, game_t *game)
{
    int n = 1440;
    sfTexture *save = move->my_texture;

    if ((bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0
        && move->item.key == false) ||
        (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0
        && move->item.sword == false)) {
        move->obs.next_map = false;
        return;
    }
    select_map_next(move, text, game);
    free_obs(move);
    init_obstacle(move);
    check_map_sound_go(move);
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0)
        n = -720, display_change_up(move, save, 0, n);
    else
        display_change_first(move, save, 0, n);
    check_map_sound(move);
    move->obs.display_text_next = false;
}

void change_map_back(raccoonmove_t *move, game_t *game)
{
    int o = 0;
    int n = -1440;
    int p = 0;
    sfTexture *save = move->my_texture;

    p = select_map_back(move, game, 0);
    free_obs(move);
    init_obstacle(move);
    check_map_sound_go(move);
    if (p == 5) {
        n = 720;
        display_change_down(move, save, o, n);
    }
    else
        display_change_second(move, save, o, n);
    check_map_sound(move);
    move->obs.back_map = false;
    move->obs.display_text_back = false;
}
