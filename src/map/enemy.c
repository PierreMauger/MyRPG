/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void load_pos_enemy(raccoonmove_t *move, int x, int y)
{
    sfVector2f pos = {1400, 890};

    move->enemy[x][y].pos = pos;
    sfSprite_setPosition(move->enemy[x][y].my_sprite, move->enemy[x][y].pos);
}

static void load_texture_enemy(raccoonmove_t *move)
{
    int x = 0;
    int y = 0;

    while (x != 4) {
        while (move->enemy[x][y].last == false) {
            move->enemy[x][y].my_texture =
                sfTexture_createFromFile(RACCOONBOSS, NULL);
            move->enemy[x][y].my_sprite = sfSprite_create();
            sfSprite_setTexture(move->enemy[x][y].my_sprite,
                move->enemy[x][y].my_texture, sfTrue);
            load_pos_enemy(move, x, y);
            y++;
        }
        x++;
        y = 0;
    }
}

int init_enemy(raccoonmove_t *move)
{
    move->enemy = malloc(sizeof(enemy_t *) * 4);
    move->enemy[0] = malloc(sizeof(enemy_t) * 1);
    move->enemy[0][0].last = true;
    move->enemy[1] = malloc(sizeof(enemy_t) * 2);
    move->enemy[1][0].last = false;
    move->enemy[1][1].last = true;
    move->enemy[2] = malloc(sizeof(enemy_t) * 2);
    move->enemy[2][0].last = true;
    move->enemy[3] = malloc(sizeof(enemy_t) * 3);
    move->enemy[3][0].last = true;
    load_texture_enemy(move);
    return (0);
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
    int y = 0;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0 && x == -1)
        x = 0;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0 && x == -1)
        x = 1;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0 && x == -1)
        x = 2;
    if (bstrcmp(move->obs.fl_map_obstacle, MAP3) == 0 && x == -1)
        x = 3;
    while (move->enemy[x][y].last == false) {
        if (check_hit_enemy(move, x, y) == 1)
            move->enemy[x][y].interaction = true;
        sfRenderWindow_drawSprite(
            move->window, move->enemy[x][y].my_sprite, NULL);
        y++;
    }
}