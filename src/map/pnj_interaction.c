/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void change_anim_npc_run(raccoonmove_t *move, int p)
{
    sfIntRect first = {0, 0, 91, 182};

    if (move->animrac.anim_npc_run == 0) {
        move->pnj.my_texture = sfTexture_createFromFile(PNJRUN, &first);
        move->animrac.anim_npc_run = 1;
        p++;
    }
    if (move->animrac.anim_npc_run == 1 && p == 0) {
        first.left += 91;
        move->pnj.my_texture = sfTexture_createFromFile(PNJRUN, &first);
        move->animrac.anim_npc_run = 2;
        p++;
    }
    if (move->animrac.anim_npc_run == 2 && p == 0) {
        first.left += 182;
        move->pnj.my_texture = sfTexture_createFromFile(PNJRUN, &first);
        move->animrac.anim_npc_run = 0;
    }
}

void change_anim_npc(raccoonmove_t *move, int p)
{
    sfIntRect first = {0, 0, 91, 182};

    if (move->animrac.anim_npc == 0) {
        move->pnj.my_texture = sfTexture_createFromFile(PNJ, &first);
        move->animrac.anim_npc = 1;
        p++;
    }
    if (move->animrac.anim_npc == 1 && p == 0) {
        first.left += 91;
        move->pnj.my_texture = sfTexture_createFromFile(PNJ, &first);
        move->animrac.anim_npc = 2;
        p++;
    }
    if (move->animrac.anim_npc == 2 && p == 0) {
        first.left += 182;
        move->pnj.my_texture = sfTexture_createFromFile(PNJ, &first);
        move->animrac.anim_npc = 0;
    }
}

int check_pnj_col(raccoonmove_t *move)
{
    int x = move->pnj.pnj_pos.x;
    int y = move->pnj.pnj_pos.y;

    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) != 0)
        return (0);
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
    close(fd);
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
