/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void init_quest_text(game_t *game)
{
    game->qtext = malloc(sizeof(quest_text_t));
    game->qtext->delay = 100000;
    game->qtext->index = 0;
    game->qtext->str_index = 0;
    game->qtext->size_font = 60;
    game->qtext->save = NULL;
    game->qtext->size = (sfVector2f){1200, 200};
    game->qtext->pos = (sfVector2f){120, 550};
    game->qtext->text = sfText_create();
    sfText_setFont(game->qtext->text, game->font_fight);
    sfText_setCharacterSize(game->qtext->text, 20);
    sfText_setColor(game->qtext->text, sfWhite);
    game->qtext->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->qtext->rect, game->qtext->size);
    sfRectangleShape_setPosition(game->qtext->rect, game->qtext->pos);
    sfRectangleShape_setFillColor(game->qtext->rect,
    sfColor_fromRGBA(47, 27, 12, 220));
}

void init_quest(game_t *game)
{
    char *buffer = bread_file(JSON_QUEST, 20);

    game->quest = malloc(sizeof(quest_t));
    init_quest_text(game);
    game->quest->final_pos = (sfVector2f){200, 200};
    game->quest->start = (char **)parser(buffer, "start", 1);
    game->quest->end = (char **)parser(buffer, "end", 1);
    free(buffer);
}
