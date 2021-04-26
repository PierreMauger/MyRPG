/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void display_map_split(raccoonmove_t *move, sfSprite *old, sfVector2f new_pos)
{
    sfRenderWindow_clear(move->window, sfWhite);
    sfRenderWindow_drawSprite(move->window, old, NULL);
    sfRenderWindow_drawSprite(move->window, move->my_sprite, NULL);
    display_mykey(move, new_pos.x, new_pos.y);
    sfRenderWindow_display(move->window);
}

void display_change_down(raccoonmove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f old_pos = {0, o};
    sfVector2f new_pos = {0, n};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue);
    while (old_pos.y > -720) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        display_map_split(move, old, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.y -= 20, new_pos.y -= 20, sfClock_restart(clock);
    }
    new_pos.y = 0;
    sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_up(raccoonmove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f old_pos = {0, o};
    sfVector2f new_pos = {0, n};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue);
    while (new_pos.y < 0) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        display_map_split(move, old, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.y += 20, new_pos.y += 20, sfClock_restart(clock);
    }
    new_pos.y = 0;
    sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_first(raccoonmove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f old_pos = {o, 0};
    sfVector2f new_pos = {n, 0};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue);
    while (new_pos.x > 0) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        display_map_split(move, old, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.x -= 20, new_pos.x -= 20, sfClock_restart(clock);
    }
    new_pos.x = 0;
    sfSprite_setPosition(move->my_sprite, new_pos);
}

void display_change_second(raccoonmove_t *move, sfTexture *save, int o, int n)
{
    sfSprite *old = sfSprite_create();
    sfVector2f old_pos = {o, 0};
    sfVector2f new_pos = {n, 0};
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(old, save, sfTrue);
    while (old_pos.x < 1440) {
        while (sfRenderWindow_pollEvent(move->window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(move->window);
        sfSprite_setPosition(old, old_pos);
        sfSprite_setPosition(move->my_sprite, new_pos);
        display_map_split(move, old, new_pos);
        if (sfClock_getElapsedTime(clock).microseconds >= 15000)
            old_pos.x += 20, new_pos.x += 20, sfClock_restart(clock);
    }
    new_pos.x = 0;
    sfSprite_setPosition(move->my_sprite, new_pos);
}