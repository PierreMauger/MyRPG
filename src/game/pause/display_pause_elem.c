/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static void display_pause_back(game_t *game)
{
    sfVector2f size = {40, 40};
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/pause_back.png", NULL);
    sfSprite *my_sprite = sfSprite_create();

    sfSprite_setScale(my_sprite, size);
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}

void display_pause(game_t *game)
{
    sfVector2f size = {1, 1};
    sfVector2f pos = {1920 / 2 - 400, 1080 / 2 - 350};
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/pause.png", NULL);
    sfSprite *my_sprite = sfSprite_create();

    display_pause_back(game);
    sfSprite_setScale(my_sprite, size);
    sfSprite_setPosition(my_sprite, pos);
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}

void display_arrow(game_t *game, int *i)
{
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/fleche.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f size = {0.2, 0.2};
    sfVector2f pos = {1920 / 2 - 230, 1080 / 2 - 200};
    int check = 0;

    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfSprite_setScale(my_sprite, size);
    while (*i != check) {
        pos.y += 90;
        check++;
    }
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}
