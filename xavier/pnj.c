/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int create_pnj(raccoonmove_t *move)
{
    sfVector2f size = {0.2, 0.2};

    move->pnj.my_texture = sfTexture_createFromFile("sprite/pnj.png", NULL);
    move->pnj.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->pnj.my_sprite, move->pnj.my_texture, sfTrue);
    srand(time(NULL));
    move->pnj.pnj_pos.x = (rand() % (600 - 150 + 1)) + 150;
    move->pnj.pnj_pos.y = (rand() % (650 - 450 + 1)) + 450;
    move->pnj.exist = true;
    move->pnj.last_dir = -1;
    sfSprite_scale(move->pnj.my_sprite, size);
    move->sentence = malloc(sizeof(char *) * 3);
    move->sentence[0] = PNJ_SPEAK_FIRST;
    move->sentence[1] = PNJ_SPEAK_SECOND;
    move->sentence[2] = NULL;
    return (0);
}

static int display_pnj(raccoonmove_t *move)
{
    sfSprite_setPosition(move->pnj.my_sprite, move->pnj.pnj_pos);
    sfRenderWindow_drawSprite(move->window, move->pnj.my_sprite, NULL);
    return (0);
}

static int pnj_path(raccoonmove_t *move, int direction)
{
    if (direction > 3) {
        direction = move->pnj.last_dir;
        if (direction == 0 && move->pnj.pnj_pos.x > 152)
            move->pnj.pnj_pos.x -= move->pnj.speed_pnj;
        if (direction == 1 && move->pnj.pnj_pos.x < 599)
            move->pnj.pnj_pos.x += move->pnj.speed_pnj;
        if (direction == 2 && move->pnj.pnj_pos.y > 452)
            move->pnj.pnj_pos.y -= move->pnj.speed_pnj;
        if (direction == 3 && move->pnj.pnj_pos.y < 648)
            move->pnj.pnj_pos.y += move->pnj.speed_pnj;
    }
    else
        move->pnj.last_dir = direction;
    return (0);
}

static int move_pnj(raccoonmove_t *move)
{
    int direction = direction = rand() % 250;

    if (move->pnj.last_dir == -1)
        direction = rand() % 4;
    if (direction == 0 && move->pnj.pnj_pos.x > 152)
        move->pnj.pnj_pos.x -= move->pnj.speed_pnj;
    if (direction == 1 && move->pnj.pnj_pos.x < 599)
        move->pnj.pnj_pos.x += move->pnj.speed_pnj;
    if (direction == 2 && move->pnj.pnj_pos.y > 452)
        move->pnj.pnj_pos.y -= move->pnj.speed_pnj;
    if (direction == 3 && move->pnj.pnj_pos.y < 648)
        move->pnj.pnj_pos.y += move->pnj.speed_pnj;
    if (move->pnj.last_dir == -1) {
        move->pnj.last_dir = direction;
        return (0);
    }
    pnj_path(move, direction);
    return (0);
}

int pnj(raccoonmove_t *move)
{
    if (my_strcmp(move->obs.fl_map_obstacle, "json/map1.json") != 0)
        return (1);
    if (move->pnj.interaction == true) {
        display_pnj(move);
        return (2);
    }
    if (move->pnj.exist == false)
        create_pnj(move);
    move_pnj(move);
    display_pnj(move);
    return (0);
}