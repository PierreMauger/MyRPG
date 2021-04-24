/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int create_sentence_chest(raccoonmove_t *move, text_t *text)
{
    if (move->chest.nb_chest == 1 && move->chest.already_open_first == true)
        return (1);
    if (move->chest.nb_chest == 2 && move->chest.already_open_second == true)
        return (1);
    move->chest.chest_open = true;
    move->sentence = malloc(sizeof(char *) * 3);
    if (move->chest.nb_chest == 1) {
        move->sentence[0] = CHEST1_SPEAK_FIRST;
        move->sentence[1] = CHEST1_SPEAK_SECOND;
        move->chest.already_open_first = true;
    }
    if (move->chest.nb_chest == 2) {
        move->sentence[0] = CHEST2_SPEAK_FIRST;
        move->sentence[1] = CHEST2_SPEAK_SECOND;
        move->chest.already_open_second = true;
    }
    move->sentence[2] = NULL;
    text->color = 120;
    text->size_box.x = 720;
    return (0);
}

int chest_open(raccoonmove_t *move, text_t *text)
{
    return (0);
}