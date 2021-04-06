/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void init_quest_text(game_t *game)
{
    game->text = malloc(sizeof(quest_text_t));
    game->text->delay = 100000;
    game->text->index = 0;
    game->text->str_index = 0;
    game->text->size_font = 60;
    game->text->save = NULL;
    game->text->size = (sfVector2f){1200, 200};
    game->text->pos = (sfVector2f){120, 550};
    game->text->text = sfText_create();
    sfText_setFont(game->text->text, game->font_fight);
    sfText_setCharacterSize(game->text->text, 20);
    sfText_setColor(game->text->text, sfWhite);
    game->text->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->text->rect, game->text->size);
    sfRectangleShape_setPosition(game->text->rect, game->text->pos);
    sfRectangleShape_setFillColor(game->text->rect,
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
