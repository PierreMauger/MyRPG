/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

bool start_game(game_t *game) 
{
    if (sfKeyboard_isKeyPressed(sfKeyG)) {
        return (true);
    }
    return (false);
}

void menu_play(game_t *game, menu_t *menu)
{
    menu->music = sfMusic_createFromFile("src/menu/rpg_music.ogg");
    if (start_game(game) == false) {
        //sfMusic_play(menu->music);
        sfRenderWindow_drawSprite(GET_WINDOW, menu->sprite, NULL);
    }
}

menu_t *main_menu(game_t *game)
{   
    menu_t *menu = malloc(sizeof(menu_t));
    menu->pos = (sfVector2f){0, 0};
    menu->rect = (sfIntRect){0, 0, 1920, 1080};
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("src/menu/menu_test.jpg", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setPosition(menu->sprite, menu->pos);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    return (menu);
}