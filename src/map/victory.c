/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include "button.h"

static void event_win_screen(game_t *game, button_t **list)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW);
    if (game->event.type == sfEvtMouseButtonPressed) {
        game->mouse_pos = sfMouse_getPositionRenderWindow(GET_WINDOW);
        if (is_mouse_on_button(game, list[0]))
            sfRenderWindow_close(GET_WINDOW);
    }
}

void my_victory(game_t *game)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/win.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 200, 75};
    button_t **list = list_button(2);

    list[0] = create_button((sfVector2f){320, 200}, EXIT_PATH, rect);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event))
            event_win_screen(game, list);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        display_shape_block(shape, game, list);
        sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
        sfRenderWindow_display(GET_WINDOW);
    }
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}

void my_loose(game_t *game)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfTexture *my_texture = sfTexture_createFromFile
        ("ressources/sprites/loose.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 200, 75};
    button_t **list = list_button(2);

    list[0] = create_button((sfVector2f){320, 200}, EXIT_PATH, rect);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event))
            event_win_screen(game, list);
        sfRenderWindow_clear(GET_WINDOW, sfWhite);
        display_parallax(game);
        display_shape_block(shape, game, list);
        sfRenderWindow_drawSprite(GET_WINDOW, my_sprite, NULL);
        sfRenderWindow_display(GET_WINDOW);
    }
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
}