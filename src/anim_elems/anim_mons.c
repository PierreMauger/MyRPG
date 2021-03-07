/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void anim_mons(game_t *game)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    while (temp != NULL) {
        move_rect(&temp->rect, temp->width, temp->width * temp->nb_anim);
        temp = temp->next;
    }
    while (temp2 != NULL) {
        move_rect(&temp2->rect, temp2->width, temp2->width * temp2->nb_anim);
        temp2 = temp2->next;
    }
}
