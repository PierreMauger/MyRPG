/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void displ_all(sfRenderWindow *window, raccoonmove_t *move, text_t *text)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, move->my_sprite, NULL);
    if (move->pnj.exist == true)
        display_pnj(move);
    display_mykey(move, 0, 0);
    my_perso(window, move);
    check_if_combat(move);
    if (check_use_now(move) >= 1)
        display_use(move);
    if (text->clock)
        text_defil(move->sentence[text->str_index], text, window);
    if (move->chest.chest_open == true)
        chest_open(move);
}

void check_change_map(raccoonmove_t *move, text_t *text)
{
    if (move->obs.next_map == true)
        change_map_next(move, text);
    if (move->obs.back_map == true)
        change_map_back(move);
}
