/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int check_pnj_col(raccoonmove_t *move)
{
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) != 0)
        return (0);
    int x = move->pnj.pnj_pos.x;
    int y = move->pnj.pnj_pos.y;

    if ((x >= move->raccoon_pos.x - 30 && x <= move->raccoon_pos.x + 30)
        && (y >= move->raccoon_pos.y - 30 && y <= move->raccoon_pos.y + 30)) {
        return (1);
    }
    return (0);
}

void create_sentence_pnj(raccoonmove_t *move, text_t *text)
{
    move->pnj.interaction = true;
    text->display = true;
    move->sentence = malloc(sizeof(char *) * 3);
    move->sentence[0] = PNJ_SPEAK_FIRST;
    move->sentence[1] = PNJ_SPEAK_SECOND;
    move->sentence[2] = NULL;
    text->pos.x = move->raccoon_pos.x - 220;
    text->pos.y = move->raccoon_pos.y + 100;
}
