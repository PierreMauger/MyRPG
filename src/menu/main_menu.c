/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

void move_bg(sfSprite *spr, int spd, struct game_object *obj)
{
    sfClock *clock;
    clock = sfClock_create();
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

struct game_object *create_object(const char *path, sfVector2f pos, sfIntRect r)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, r);
    struct game_object *obj = malloc(sizeof(struct game_object));

    obj->texture = texture;
    obj->sprite = sprite;
    obj->pos = pos;
    obj->r = r;
    obj->count_jump = 0;
    return (obj);
}

void display_menu(game_t *game, button_t *btn)
{
    //sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW);
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f pos_raccoon = {150, 860};
    sfIntRect rect = {0, 0, 64, 64};
    sfClock *clock = sfClock_create();
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("ressources/menu/raccoon.png", &rect);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos_raccoon);
    display_shape_block(shape, game, btn);
    move_racoon_menu(game, rect, clock, sprite);
    sfRenderWindow_drawSprite(GET_WINDOW, sprite, NULL);
}

void display_shape_block(sfRectangleShape *shape, game_t *game, button_t *btn)
{
    sfIntRect rect = {0, 0, 156, 56};
    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, (sfVector2f){400, 1080});
    sfRectangleShape_setFillColor(shape, (sfColor){255, 255,255, 200});
    sfRectangleShape_setPosition(shape, (sfVector2f){300, 0});
    sfRenderWindow_drawRectangleShape(GET_WINDOW, shape, NULL);
    button_t *btn1 = create_button((sfVector2f){320, 50}, "play_button.jpg", rect);
    draw_button(game, btn1);
}

struct game_object **obj_n(int nbr_assets)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 1920, 1080};
    struct game_object **tab = malloc(sizeof(struct game_object) * nbr_assets);

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
