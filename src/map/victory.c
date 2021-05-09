/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void event_win_screen(game_t *game)
{
    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(GET_WINDOW);
    }
}

void my_victory(game_t *game)
{
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/win.png", NULL);
    sfSprite *my_sprite = sfSprite_create();

    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_win_screen(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
        sfRenderWindow_display(GET_WINDOW);
    }
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}

void my_loose(game_t *game)
{
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/loose.png", NULL);
    sfSprite *my_sprite = sfSprite_create();

    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_win_screen(game);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
        sfRenderWindow_display(GET_WINDOW);
    }
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}