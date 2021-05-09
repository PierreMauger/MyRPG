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

static int get_x_enemy(raccoonmove_t *move, int x)
{
    if (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0 && x == -1)
        x = 0;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && x == -1)
        x = 1;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && x == -1)
        x = 2;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0 && x == -1)
        x = 3;
    return (x);
}

static void anim_enemy(raccoonmove_t *move, int p, int x, int y)
{
    sfIntRect first = {0, 0, 64, 128};

    if (move->animrac.anim_ene == 0) {
        move->enemy[x][y].my_texture = sfTexture_createFromFile(RCBOSS, &first);
        move->animrac.anim_ene = 1;
        p++;
    }
    if (move->animrac.anim_ene == 1 && p == 0) {
        first.left += 128;
        move->enemy[x][y].my_texture = sfTexture_createFromFile(RCBOSS, &first);
        move->animrac.anim_ene = 2;
        p++;
    }
    if (move->animrac.anim_ene == 2 && p == 0) {
        first.left += 64;
        move->enemy[x][y].my_texture = sfTexture_createFromFile(RCBOSS, &first);
        move->animrac.anim_ene = 0;
    }
}

void check_if_combat(raccoonmove_t *move)
{
    int x = -1;

    x = get_x_enemy(move, x);
    for (int y = 0; move->enemy[x][y].last == false
        && move->enemy[x][y].dead == false; y++) {
        if (check_hit_enemy(move, x, y) == 1)
            move->enemy[x][y].interaction = true;
        if (sfClock_getElapsedTime(move->animrac.enemy_clock)
            .microseconds >= 200000 && move->anim == false) {
            sfTexture_destroy(move->enemy[x][y].my_texture);
            anim_enemy(move, 0, x, y);
            sfSprite_setTexture(move->enemy[x][y].my_sprite,
                move->enemy[x][y].my_texture, sfTrue);
            sfClock_restart(move->animrac.enemy_clock);
        }
        sfRenderWindow_drawSprite(
            move->window, move->enemy[x][y].my_sprite, NULL);
    }
}
