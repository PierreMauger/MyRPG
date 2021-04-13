/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void display_map_split(dinomove_t *move, sfSprite *old)
{
    sfRenderWindow_clear(move->window, sfWhite);
    sfRenderWindow_drawSprite(move->window, old, NULL);
    sfRenderWindow_drawSprite(move->window, move->my_sprite, NULL);
    sfRenderWindow_display(move->window);
}

void display_change_down(dinomove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f size = {0.75, 0.75};
    sfVector2f old_pos = {0, o};
    sfVector2f new_pos = {0, n};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue), sfSprite_setScale(old, size);
    while (new_pos.x > 0) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.y -= 20, new_pos.y -= 20, sfClock_restart(clock);
        display_map_split(move, old);
    }
    new_pos.y = 0, sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_up(dinomove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f size = {0.75, 0.75};
    sfVector2f old_pos = {o, 0};
    sfVector2f new_pos = {n, 0};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue), sfSprite_setScale(old, size);
    while (new_pos.x > 0) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.x -= 20, new_pos.x -= 20, sfClock_restart(clock);
        display_map_split(move, old);
    }
    new_pos.x = 0, sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_first(dinomove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f size = {0.75, 0.75};
    sfVector2f old_pos = {o, 0};
    sfVector2f new_pos = {n, 0};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue), sfSprite_setScale(old, size);
    while (new_pos.x > 0) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.x -= 20, new_pos.x -= 20, sfClock_restart(clock);
        display_map_split(move, old);
    }
    new_pos.x = 0, sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_second(dinomove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f size = {0.75, 0.75};
    sfVector2f old_pos = {o, 0};
    sfVector2f new_pos = {n, 0};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue), sfSprite_setScale(old, size);
    while (old_pos.x < 1440) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.x += 20, new_pos.x += 20, sfClock_restart(clock);
        display_map_split(move, old);
    }
    new_pos.x = 0, sfSprite_setPosition(move->my_sprite, new_pos);
    move->dino_pos.x = 1359;
}