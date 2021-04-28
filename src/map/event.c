/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int reset_text(text_t *text, raccoonmove_t *move)
{
    text->clock = NULL;
    text->color = 12;
    text->save = NULL;
    text->index = 0;
    text->str_index = 0;
    move->pnj.interaction = false;
    move->chest.chest_open = false;
    text->size_box.x = 800;
    free(text->save);
    free(move->sentence);
    return (0);
}

int my_event_text(sfEvent event, char **str, text_t *text, raccoonmove_t *move)
{
    if (event.type == sfEvtMouseButtonPressed && text->clock != NULL
        && str[text->str_index + 1] == NULL) {
        reset_text(text, move);
        return (0);
    }
    if (event.type == sfEvtMouseButtonPressed && text->clock != NULL
        && str[text->str_index + 1] != NULL) {
        text->str_index++;
        text->clock = NULL;
        free(text->save);
        text->save = NULL;
        text->index = 0;
        text->clock = sfClock_create();
    }
    if (text->clock == NULL) {
        text->clock = sfClock_create();
        text->pos.x = move->raccoon_pos.x - 220;
        text->pos.y = move->raccoon_pos.y + 100;
    }
}

static int k_map(raccoonmove_t *move, sfEvent event, text_t *text)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (move->speed == 3)
            move->speed *= 2;
        else
            move->speed /= 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyL))
        load_save(move);
    if (sfKeyboard_isKeyPressed(sfKeyE) && check_pnj_col(move) == 1)
        create_sentence_pnj(move);
    if (sfKeyboard_isKeyPressed(sfKeyE) && move->chest.col_chest == true)
        create_sentence_chest(move, text);
    if (sfKeyboard_isKeyPressed(sfKeyE) && move->key.col_key == true)
        move->key.taken = true;
    if (sfKeyboard_isKeyPressed(sfKeyE)
        && move->obs.display_text_next == true)
        move->obs.next_map = true;
    if (sfKeyboard_isKeyPressed(sfKeyE)
        && move->obs.display_text_back == true)
        move->obs.back_map = true;
}

int map_event(raccoonmove_t *move, sfEvent event, text_t *text)
{
    if (move->pnj.interaction == true || move->chest.chest_open == true)
        my_event_text(event, move->sentence, text, move);
    if (event.type == sfEvtKeyPressed) {
        k_map(move, event, text);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(move->window);
    if (move->pnj.interaction == true || move->chest.chest_open == true)
        move->anim = true;
    else
        move->anim = false;
}