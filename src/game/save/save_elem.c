/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** bootstrap
*/

#include "game.h"

static void split_write_in_json_save(FILE *fp, game_t *game)
{
    if (game->move->item.key == true)
        fwrite("\"true\"", 1, 6, fp);
    else
        fwrite("\"false\"", 1, 7, fp);
    fwrite(",\n\t\t\"boot\": ", 1, 12, fp);
    if (game->move->item.boot == true)
        fwrite("\"true\"", 1, 6, fp);
    else
        fwrite("\"false\"", 1, 7, fp);
    fwrite(",\n\t\t\"sword\": ", 1, 13, fp);
    if (game->move->item.sword == true)
        fwrite("\"true\"", 1, 6, fp);
    else
        fwrite("\"false\"", 1, 7, fp);
    fwrite(",\n\t\t\"door\": ", 1, 12, fp);
    if (game->move->item.door == true)
        fwrite("\"true\"", 1, 6, fp);
    else
        fwrite("\"false\"", 1, 7, fp);
    fwrite(",\n\t},\n]", 1, 7, fp);
}

static void write_in_json_save(FILE *fp, game_t *game)
{
    fwrite(",\n\t\t\"raccoon_pos.y\": ", 1, 21, fp);
    fwrite(my_itoa(game->move->raccoon_pos.y), 1,
        bstrlen(my_itoa(game->move->raccoon_pos.y)), fp);
    fwrite(",\n\t\t\"png_x\": ", 1, 13, fp);
    if (game->move->pnj.exist == true)
        fwrite(my_itoa(game->move->pnj.pnj_pos.x), 1,
            bstrlen(my_itoa(game->move->pnj.pnj_pos.x)), fp);
    fwrite(",\n\t\t\"png_y\": ", 1, 13, fp);
    if (game->move->pnj.exist == true)
        fwrite(my_itoa(game->move->pnj.pnj_pos.y), 1,
            bstrlen(my_itoa(game->move->pnj.pnj_pos.y)), fp);
    fwrite(",\n\t\t\"key\": ", 1, 11, fp);
    split_write_in_json_save(fp, game);
}

int save_elem(game_t *game)
{
    FILE *fp = fopen("ressources/json/save.json", "w");

    if (fp == NULL)
        return (1);
    fwrite("[\n\t{\n\t\t", 1, 7, fp);
    fwrite("\"id\": 1,\n\t\t", 1, 11, fp);
    fwrite("\"map\": \"", 1, 8, fp);
    fwrite(game->move->obs.fl_map_obstacle, 1,
        bstrlen(game->move->obs.fl_map_obstacle), fp);
    fwrite("\",\n\t\t\"raccoon_pos.x\": ", 1, 22, fp);
    fwrite(my_itoa(game->move->raccoon_pos.x), 1,
        bstrlen(my_itoa(game->move->raccoon_pos.x)), fp);
    write_in_json_save(fp, game);
    fclose(fp);
    return (0);
}
