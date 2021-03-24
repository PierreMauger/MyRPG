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
        move_rect(&temp->texture->rect, temp->texture->rect.width, temp->texture->rect.width * temp->texture->nb_anim);
        temp = temp->next;
    }
    while (temp2 != NULL) {
        move_rect(&temp2->texture->rect, temp2->texture->rect.width, temp2->texture->rect.width * temp2->texture->nb_anim);
        temp2 = temp2->next;
    }
}
