/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void anim_mons(game_t *game)
{
    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        move_rect(&temp->texture->rect, MONS_WIDTH(temp),
        temp->texture->nb_anim);
    }
    for (mons_t *temp = game->e_mons; temp; temp = temp->next) {
        move_rect(&temp->texture->rect, MONS_WIDTH(temp),
        temp->texture->nb_anim);
    }
}
