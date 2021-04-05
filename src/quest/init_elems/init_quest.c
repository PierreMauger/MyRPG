/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_quest(game_t *game)
{
    char *buffer = bread_file(JSON_QUEST, 20);

    game->quest = malloc(sizeof(quest_t));
    game->quest->final_pos = (sfVector2f){200, 200};
    game->quest->start = (char **)parser(buffer, "start", 1);
    game->quest->end = (char **)parser(buffer, "end", 1);
    free(buffer);
}
