/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void my_perso(sfRenderWindow *window, dinomove_t *move)
{
    sfTexture *back = sfTexture_createFromFile("dino.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f sprite_size = {0.6, 0.6};
    sfSprite_setPosition(my_spr, move->dino_pos);
    sfSprite_scale(my_spr, sprite_size);

    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

void display_next_map(dinomove_t *move)
{
    sfFont* font = sfFont_createFromFile("../ressources/font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos;
    int i = 0;

    while (my_strcmp(move->obs.type[i], " \"nextmap\"") != 0)
        i++;
    pos.x = move->obs.obstacle[i][0];
    pos.y = move->obs.obstacle[i][2];
    sfText_setString(text, "press k");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, pos);
    sfText_setRotation(text, 90);
    sfRenderWindow_drawText(move->window, text, NULL);
    sfText_destroy(text), sfFont_destroy(font);
}