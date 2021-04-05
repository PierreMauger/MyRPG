/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

bool start_game(game_t *game, menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        menu->music_playing = true;
        return (true);
    }
    return (false);
}

void menu_play(game_t *game, menu_t *menu)
{
    menu->music = sfMusic_createFromFile("ressources/menu/rpg_music.ogg");
    if (start_game(game, menu) == false && menu->music_playing == false) {
        menu->music_playing = true;
        sfMusic_getLoop(menu->music);
        sfMusic_play(menu->music);
        sfRenderWindow_drawSprite(GET_WINDOW, menu->sprite, NULL);
    }
    else {
        sfMusic_pause(menu->music);
        sfMusic_destroy(menu->music);
    }
}

menu_t *main_menu(game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->pos = (sfVector2f){0, 0};
    menu->rect = (sfIntRect){0, 0, 1920, 1080};
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("ressources/menu/menu_test.jpg", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setPosition(menu->sprite, menu->pos);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    menu->music_playing = false;
    return (menu);
}
