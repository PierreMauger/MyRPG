/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static int split_write_in_json_save(FILE *fp, game_t *game)
{
    fwrite(",\n\t\t\"key\": ", 1, 11, fp);
    if (game->move->key.taken == true)
        fwrite("true", 1, 4, fp);
    else
        fwrite("false", 1, 5, fp);
    fwrite(",\n\t\t\"boot\": ", 1, 12, fp);
    if (game->move->boot == true)
        fwrite("true", 1, 4, fp);
    else
        fwrite("false", 1, 5, fp);
    fwrite(",\n\t},\n]", 1, 7, fp);
}

static int write_in_json_save(FILE *fp, game_t *game)
{
    fwrite("[\n\t{\n\t\t", 1, 7, fp);
    fwrite("\"map\": \"", 1, 8, fp);
    fwrite(game->move->obs.fl_map_obstacle, 1,
        bstrlen(game->move->obs.fl_map_obstacle), fp);
    fwrite("\",\n\t\t\"raccoon_pos\": ", 1, 20, fp);
    fwrite(my_itoa(game->move->raccoon_pos.x), 1,
        bstrlen(my_itoa(game->move->raccoon_pos.x)), fp);
    fwrite("-", 1, 1, fp);
    fwrite(my_itoa(game->move->raccoon_pos.y), 1,
        bstrlen(my_itoa(game->move->raccoon_pos.y)), fp);
    fwrite(",\n\t\t\"png_pos\": ", 1, 15, fp);
    if (game->move->pnj.exist == true) {
        fwrite(my_itoa(game->move->pnj.pnj_pos.x), 1,
            bstrlen(my_itoa(game->move->pnj.pnj_pos.x)), fp);
        fwrite("-", 1, 1, fp);
        fwrite(my_itoa(game->move->pnj.pnj_pos.y), 1,
            bstrlen(my_itoa(game->move->pnj.pnj_pos.y)), fp);
    }
    split_write_in_json_save(fp, game);
    return (0);
}

int save_elem(game_t *game)
{
    int fd = 0;
    int ret = 0;
    FILE *fp = fopen("ressources/json/save.json", "w");

    if (fp == NULL)
        return (1);
    write_in_json_save(fp, game);
    fclose(fp);
    return (0);
}