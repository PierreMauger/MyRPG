/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_turn_arrow(game_t *game)
{
    game->ind->arr = malloc(sizeof(arrow_t));
    game->ind->arr->rect = (sfIntRect){0, 0, 48, 64};
    game->ind->arr->texture = sfTexture_createFromFile(ARROW_IMG, NULL);
    game->ind->arr->sprite = sfSprite_create();
}

void init_turn_ind(game_t *game)
{
    game->ind = malloc(sizeof(indicator_t));
    init_turn_arrow(game);
    game->ind->damage = sfText_create();
    sfText_setFont(game->ind->damage, game->font_fight);
    sfText_setCharacterSize(game->ind->damage, 75);
    sfText_setColor(game->ind->damage, sfYellow);
    game->ind->att_name = sfText_create();
    sfText_setFont(game->ind->att_name, game->font_fight);
    sfText_setCharacterSize(game->ind->att_name, 50);
    sfText_setColor(game->ind->att_name, sfBlack);
    game->ind->ptr_mons = NULL;
    game->ind->ptr_skill = NULL;
    game->ind->team = NULL;
    game->ind->target = NULL;
    CURR_ATT = 0;
}
