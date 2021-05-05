/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void check_if_combat_start(game_t *game)
{
    int x = -1;

    if (bstrcmp(game->move->obs.fl_map_obstacle, MAP0) == 0 && x == -1)
        x = 0;
    if (bstrcmp(game->move->obs.fl_map_obstacle, MAP1) == 0 && x == -1)
        x = 1;
    if (bstrcmp(game->move->obs.fl_map_obstacle, MAP2) == 0 && x == -1)
        x = 2;
    if (bstrcmp(game->move->obs.fl_map_obstacle, MAP3) == 0 && x == -1)
        x = 3;
    for (int y = 0; game->move->enemy[x][y].last == false; y++) {
        if (game->move->enemy[x][y].interaction == true) {
            game->in_fight = 1;
            game->move->enemy[x][y].dead = true;
            game->move->enemy[x][y].interaction = false;
            game->move->enemy_info.nb_enemy = x + 1;
        }
    }
}

static int check_hit_enemy(raccoonmove_t *move, int x, int y)
{
    int k = move->enemy[x][y].pos.x;
    int j = move->enemy[x][y].pos.y;

    if ((k >= move->raccoon_pos.x - 30 && k <= move->raccoon_pos.x + 30)
        && (j >= move->raccoon_pos.y - 30 && j <= move->raccoon_pos.y + 30)) {
        return (1);
    }
    return (0);
}

void check_if_combat(raccoonmove_t *move)
{
    int x = -1;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0 && x == -1)
        x = 0;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && x == -1)
        x = 1;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && x == -1)
        x = 2;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0 && x == -1)
        x = 3;
    for (int y = 0; move->enemy[x][y].last == false && move->enemy[x][y].dead
    == false; y++) {
        if (check_hit_enemy(move, x, y) == 1)
            move->enemy[x][y].interaction = true;
        sfRenderWindow_drawSprite(
            move->window, move->enemy[x][y].my_sprite, NULL);
    }
}
