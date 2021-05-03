/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void display_mykey(raccoonmove_t *move, int x, int y)
{
    sfVector2f pos_key = {1792 + x, 917 + y};

    if (move->item.key == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0) {
        sfSprite_setPosition(move->key.my_sprite, pos_key);
        sfRenderWindow_drawSprite(move->window, move->key.my_sprite, NULL);
    }
}

void my_perso(sfRenderWindow *window, raccoonmove_t *move)
{
    sfTexture *back = sfTexture_createFromFile(RACCOON, NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f sprite_size = {1, 1};
    sfSprite_setPosition(my_spr, move->raccoon_pos);
    sfSprite_scale(my_spr, sprite_size);

    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

void display_next_map(raccoonmove_t *move)
{
    sfFont* font = sfFont_createFromFile("ressources/font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos;
    int i = 0;

    while (bstrcmp(move->obs.type[i], " \"nextmap\"") != 0)
        i++;
    pos.x = move->obs.obstacle[i][0];
    pos.y = move->obs.obstacle[i][2];
    sfText_setString(text, "press E");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, pos);
    sfText_setRotation(text, 90);
    sfRenderWindow_drawText(move->window, text, NULL);
    sfText_destroy(text), sfFont_destroy(font);
}

void display_back_map(raccoonmove_t *move)
{
    sfFont* font = sfFont_createFromFile("ressources/font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos;
    int i = 0;

    while (bstrcmp(move->obs.type[i], " \"backmap\"") != 0)
        i++;
    pos.x = move->obs.obstacle[i][0] + 200;
    pos.y = move->obs.obstacle[i][2];
    sfText_setString(text, "press E");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, pos);
    sfText_setRotation(text, 90);
    sfRenderWindow_drawText(move->window, text, NULL);
    sfText_destroy(text), sfFont_destroy(font);
}