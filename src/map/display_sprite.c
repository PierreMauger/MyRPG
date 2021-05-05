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
    sfSprite_setPosition(move->my_sprite_rac, move->raccoon_pos);
    sfRenderWindow_drawSprite(window, move->my_sprite_rac, NULL);
}

int check_use_now(raccoonmove_t *move)
{
    if (move->anim == true)
        return (0);
    if (move->obs.display_text_next == true
        || move->obs.display_text_back == true)
        return (1);
    if (check_pnj_col(move) == 1)
        return (2);
    if (move->chest.col_chest == true
        && ((move->chest.already_open_first == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0)
        || (move->chest.already_open_second == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0)))
        return (3);
    if (move->key.col_key == true && move->item.key == false)
        return (4);
    return (0);
}

void display_use(raccoonmove_t *move)
{
    sfTexture *back = sfTexture_createFromFile(
        "ressources/sprites/keyboard_key_e.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f pos = {1780, 10};

    sfSprite_setPosition(my_spr, pos);
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(move->window, my_spr, NULL);
    sfTexture_destroy(back);
    sfSprite_destroy(my_spr);
}
