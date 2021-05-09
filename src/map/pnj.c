/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void create_pnj(raccoonmove_t *move)
{
    sfVector2f size = {0.9, 0.9};
    int create_rand = 0;
    long long stock = (long long)&create_rand;

    if (stock < 0)
        stock = stock * -1;
    srand(stock);
    move->pnj.my_texture = sfTexture_createFromFile(PNJ, NULL);
    move->pnj.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->pnj.my_sprite, move->pnj.my_texture, sfTrue);
    move->pnj.pnj_pos.x = (rand() % (600 - 250 + 1)) + 250;
    move->pnj.pnj_pos.y = (rand() % (650 - 500 + 1)) + 500;
    move->pnj.exist = true;
    move->pnj.last_dir = -1;
    sfSprite_setScale(move->pnj.my_sprite, size);
}

void display_pnj(raccoonmove_t *move)
{
    if (sfClock_getElapsedTime(move->animrac.npc_clock)
        .microseconds >= 300000 && move->anim == false
        && move->pnj.idle == true) {
        sfTexture_destroy(move->pnj.my_texture);
        change_anim_npc(move, 0);
        sfClock_restart(move->animrac.npc_clock);
        move->pnj.idle = false;
        sfSprite_setTexture(move->pnj.my_sprite, move->pnj.my_texture, sfTrue);
    }
    else if (sfClock_getElapsedTime(move->animrac.npc_clock)
        .microseconds >= 200000 && move->anim == false
        && move->pnj.idle == false) {
        sfTexture_destroy(move->pnj.my_texture);
        change_anim_npc_run(move, 0);
        sfClock_restart(move->animrac.npc_clock);
        sfSprite_setTexture(move->pnj.my_sprite, move->pnj.my_texture, sfTrue);
    }
    sfSprite_setPosition(move->pnj.my_sprite, move->pnj.pnj_pos);
    sfRenderWindow_drawSprite(move->window, move->pnj.my_sprite, NULL);
}

static void pnj_path(raccoonmove_t *move, int direction)
{
    if (direction > 3) {
        direction = move->pnj.last_dir;
        if (direction == 0 && move->pnj.pnj_pos.x > 252)
            move->pnj.pnj_pos.x -= move->pnj.speed_pnj;
        if (direction == 1 && move->pnj.pnj_pos.x < 599)
            move->pnj.pnj_pos.x += move->pnj.speed_pnj;
        if (direction == 2 && move->pnj.pnj_pos.y > 502)
            move->pnj.pnj_pos.y -= move->pnj.speed_pnj;
        if (direction == 3 && move->pnj.pnj_pos.y < 648)
            move->pnj.pnj_pos.y += move->pnj.speed_pnj;
    }
    else
        move->pnj.last_dir = direction;
}

static void move_pnj(raccoonmove_t *move)
{
    int direction = direction = rand() % 250;

    if (move->pnj.last_dir == -1)
        direction = rand() % 4;
    if (direction == 0 && move->pnj.pnj_pos.x > 252)
        move->pnj.pnj_pos.x -= move->pnj.speed_pnj;
    if (direction == 1 && move->pnj.pnj_pos.x < 599)
        move->pnj.pnj_pos.x += move->pnj.speed_pnj;
    if (direction == 2 && move->pnj.pnj_pos.y > 502)
        move->pnj.pnj_pos.y -= move->pnj.speed_pnj;
    if (direction == 3 && move->pnj.pnj_pos.y < 648)
        move->pnj.pnj_pos.y += move->pnj.speed_pnj;
    if (move->pnj.last_dir == -1) {
        move->pnj.last_dir = direction;
        return;
    }
    pnj_path(move, direction);
}

int pnj(raccoonmove_t *move)
{
    int y;
    int x;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) != 0)
        return (1);
    if (move->pnj.interaction == true) {
        display_pnj(move);
        return (2);
    }
    if (move->pnj.exist == false)
        create_pnj(move);
    y = move->pnj.pnj_pos.y;
    x = move->pnj.pnj_pos.x;
    move_pnj(move);
    if (y == move->pnj.pnj_pos.y && x == move->pnj.pnj_pos.x)
        move->pnj.idle = true;
    else
        move->pnj.idle = false;
    return (0);
}
