/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int event_text(sfEvent event, char **str, text_t *text, raccoonmove_t *move)
{
    if (event.type == sfEvtMouseButtonPressed && text->clock != NULL
        && str[text->str_index + 1] == NULL) {
        text->clock = NULL, free(text->save);
        text->save = NULL, text->index = 0, text->str_index = 0;
        move->pnj.interaction = false;
        return (0);
    }
    if (event.type == sfEvtMouseButtonPressed && text->clock != NULL
        && str[text->str_index + 1] != NULL) {
        text->str_index++, text->clock = NULL, free(text->save);
        text->save = NULL, text->index = 0, text->clock = sfClock_create();
    }
    if (text->clock == NULL)
        text->clock = sfClock_create();
}

static int key_pressed_map(raccoonmove_t *move, sfEvent event, int *passed)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (move->speed == 2)
            move->speed = 4;
        else
            move->speed = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && check_pnj_col(move) == 1)
        move->pnj.interaction = true;
    if (sfKeyboard_isKeyPressed(sfKeyE) && move->obs.chest_open == true)
        move->obs.chest_open = false;
    if (sfKeyboard_isKeyPressed(sfKeyE) && move->obs.col_chest == true)
        move->obs.chest_open = true;
    if (sfKeyboard_isKeyPressed(sfKeyE)
        && move->obs.display_text_next == true)
        move->obs.next_map = true;
    if (sfKeyboard_isKeyPressed(sfKeyE)
        && move->obs.display_text_back == true)
        move->obs.back_map = true;
    create_col(move->raccoon_pos.x, move->raccoon_pos.y, move, passed);
}

int map_event(raccoonmove_t *move, sfEvent event, int *passed)
{
    if (event.type == sfEvtKeyPressed) {
        key_pressed_map(move, event, passed);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(move->window);
}