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
        move_rect(&temp->mons_tex->rect, temp->mons_tex->rect.width, temp->mons_tex->rect.width * temp->mons_tex->nb_anim);
        temp = temp->next;
    }
    while (temp2 != NULL) {
        move_rect(&temp2->mons_tex->rect, temp2->mons_tex->rect.width, temp2->mons_tex->rect.width * temp2->mons_tex->nb_anim);
        temp2 = temp2->next;
    }
}
