/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr->skill;
    int x = 200;

    while (temp != NULL) {
        sfSprite_setPosition(temp->sprite, (sfVector2f){x, 100});
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
        x += 100;
    }
}