/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

sfText *create_text_btn(sfText *txt, game_t *game, button_t *btn)
{
    txt = init_font(txt, (sfVector2f){330, 60}, "./ressources/font.ttf", "MENU");
    set_size_font(txt, 100);
    set_color(txt, sfBlack);
    show_font(game, txt);
    sfVector2f pos;

    btn->f_rect = sfText_getGlobalBounds(txt);
    btn->text_pos = sfText_getPosition(txt);
    return (txt);
}
