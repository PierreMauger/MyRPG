/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void load_pos_enemy(raccoonmove_t *move, int x, int y)
{
    char *buff = get_text_open("ressources/json/enemy_pos.json");

    move->enemy[x][y].pos.x = (int)parser(buff, "enemy_pos.x", x);
    move->enemy[x][y].pos.y = (int)parser(buff, "enemy_pos.y", x);
    sfSprite_setPosition(move->enemy[x][y].my_sprite, move->enemy[x][y].pos);
    free(buff);
}

static void load_texture_enemy(raccoonmove_t *move)
{
    int y = 0;

    for (int x = 0; x != 4; x++) {
        for (y = 0; move->enemy[x][y].last != true; y++) {
            move->enemy[x][y].interaction = false;
            move->enemy[x][y].dead = false;
            move->enemy[x][y].my_texture =
                sfTexture_createFromFile(RCBOSS, NULL);
            move->enemy[x][y].my_sprite = sfSprite_create();
            sfSprite_setTexture(move->enemy[x][y].my_sprite,
                move->enemy[x][y].my_texture, sfTrue);
            load_pos_enemy(move, x, y);
        }
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
    move->enemy[2][0].last = false;
    move->enemy[2][1].last = true;
    move->enemy[3] = malloc(sizeof(enemy_t) * 2);
    move->enemy[3][0].last = false;
    move->enemy[3][1].last = true;
    load_texture_enemy(move);
    return (0);
}
