/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_quest(quest_t *quest, quest_text_t *quest_text)
{
    sfRectangleShape_destroy(quest_text->rect);
    sfText_destroy(quest_text->text);
    free(quest_text);
    bfree_array(quest->start);
    bfree_array(quest->end);
    free(quest);
}
