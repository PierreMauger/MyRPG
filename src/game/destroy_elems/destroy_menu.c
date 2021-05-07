/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_menu(menu_t *menu)
{
    sfSprite_destroy(menu->para->sprite_grass);
    sfSprite_destroy(menu->para->sprite_tree);
    sfSprite_destroy(menu->para->sprite_mont);
    sfSprite_destroy(menu->para->sprite_sky);
    sfSprite_destroy(menu->paracpy->sprite_grass);
    sfSprite_destroy(menu->paracpy->sprite_tree);
    sfSprite_destroy(menu->paracpy->sprite_mont);
    sfSprite_destroy(menu->paracpy->sprite_sky);
    sfTexture_destroy(menu->para->grass);
    sfTexture_destroy(menu->para->tree);
    sfTexture_destroy(menu->para->mont);
    sfTexture_destroy(menu->para->sky);
    sfTexture_destroy(menu->paracpy->grass);
    sfTexture_destroy(menu->paracpy->tree);
    sfTexture_destroy(menu->paracpy->mont);
    sfTexture_destroy(menu->paracpy->sky);
    free(menu->para);
    free(menu->paracpy);
    free(menu);
}