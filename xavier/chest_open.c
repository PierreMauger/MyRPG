/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int chest_open(raccoonmove_t *move, text_t *text)
{
    if (move->chest.clock_chest == NULL) {
        move->chest.clock_chest = sfClock_create();
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = CHEST_SPEAK_FIRST;
        move->sentence[1] = CHEST_SPEAK_SECOND;
        move->sentence[2] = NULL;
        move->chest.already_open = true;
        text->color = 120;
    }
    return (0);
}