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

char *get_text_open(char *filepath)
{
    int fd = 0;
    int ret = 0;
    char buff[4096];

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    ret = read(fd, buff, 4096);
    if (ret == -1)
        return (NULL);
    buff[ret] = '\0';
    close (fd);
    return (bstrdup(buff));
}

void create_sentence_pnj(raccoonmove_t *move, text_t *text)
{
    char *buff = get_text_open("ressources/json/text.json");

    move->pnj.interaction = true;
    text->display = true;
    move->sentence = malloc(sizeof(char *) * 4);
    move->sentence[0] = (char *)parser(buff, "pnj_speak_first", 1);
    move->sentence[1] = (char *)parser(buff, "pnj_speak_second", 1);
    move->sentence[2] = (char *)parser(buff, "pnj_speak_third", 1);
    move->sentence[3] = NULL;
    move->item.door = true;
    text->pos.x = move->raccoon_pos.x - 220;
    text->pos.y = move->raccoon_pos.y + 100;
    free(buff);
}
