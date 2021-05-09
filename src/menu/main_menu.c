/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

void move_bg(sfSprite *spr, int spd, obj_t *obj)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0f;
    if (seconds >= 0) {
        sfSprite_getPosition(spr);
        sfClock_restart(clock);
        obj->r.left += spd;
        if (obj->r.left >= 1920)
            obj->r.left = 0;
        sfSprite_setTextureRect(spr, obj->r);
    }
    return;
}

obj_t *create_object(const char *path, sfVector2f pos, sfIntRect r)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    obj_t *obj = malloc(sizeof(obj_t));

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, r);
    obj->texture = texture;
    obj->sprite = sprite;
    obj->pos = pos;
    obj->r = r;
    obj->count_jump = 0;
    return (obj);
}

void display_menu(game_t *game, button_t **list)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    display_shape_block(shape, game, list);
}

void display_shape_block(sfRectangleShape *shape, game_t *game, button_t **list)
{
    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, (sfVector2f){400, 1080});
    sfRectangleShape_setFillColor(shape, (sfColor){255, 255, 255, 200});
    sfRectangleShape_setPosition(shape, (sfVector2f){300, 0});
    sfRenderWindow_drawRectangleShape(GET_WINDOW, shape, NULL);
    draw_buttons(game, list);
}

obj_t **obj_n(int nbr_assets)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 1920, 1080};
    obj_t **tab = malloc(sizeof(obj_t) * nbr_assets);

    tab[0] = create_object("layer06_sky.png", pos, rect);
    tab[1] = create_object("layer05_rocks.png", pos, rect);
    tab[2] = create_object("layer04_clouds.png", pos, rect);
    tab[3] = create_object("layer03_trees.png", pos, rect);
    tab[4] = create_object("layer02_cake.png", pos, rect);
    tab[5] = create_object("layer01_ground.png", pos, rect);
    tab[1]->speed = 2;
    tab[2]->speed = 2;
    tab[3]->speed = 3;
    tab[4]->speed = 5;
    tab[5]->speed = 8;
    return (tab);
}
