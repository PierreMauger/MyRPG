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
    txt = init_font(txt, (sfVector2f){330, 60},
    "./ressources/font.ttf", "MENU");
    set_size_font(txt, 100);
    set_color(txt, sfBlack);
    show_font(game, txt);
    btn->f_rect = sfText_getGlobalBounds(txt);
    btn->text_pos = sfText_getPosition(txt);
    return (txt);
}

void move_racoon_menu(game_t *game, sfIntRect rect, sfClock *clock,
sfSprite *sprite)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100000.0f;
    if (seconds > 0.05f) {
        rect.left += 64;
        sfSprite_move(sprite, (sfVector2f){0, 0});
        sfClock_restart(clock);
        if (rect.left == 192)
            rect.left = 0;
    }
    sfRenderWindow_drawSprite(GET_WINDOW, sprite, NULL);
    return;
}
