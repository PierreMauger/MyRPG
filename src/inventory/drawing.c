/*
** EPITECH PROJECT, 2021
** droping funcs
** File description:
** drops
*/

#include "game.h"

void display_stats_sprites(inventory_t *inv, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(inv->promptsprite);

    pos.y += 50;
    sfSprite_setPosition(STATUS_SPRITE[att_p], pos);
    pos.x += 60;
    sfSprite_setPosition(STATUS_SPRITE[def_p], pos);
    pos.x += 60;
    sfSprite_setPosition(STATUS_SPRITE[spe_p], pos);
    sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[att_p], NULL);
    sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[def_p], NULL);
    sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[spe_p], NULL);
}

void display_stats_texts(game_t *game, inventory_t *inv, item_t *item)
{
    sfVector2f pos;

    sfText_setColor(inv->prompttext, sfWhite);
    pos = sfSprite_getPosition(STATUS_SPRITE[att_p]);
    pos.x += 30;
    sfText_setPosition(inv->prompttext, pos);
    set_string(inv, item, 1);
    sfRenderWindow_drawText(GET_WINDOW, inv->prompttext, NULL);
    pos = sfSprite_getPosition(STATUS_SPRITE[def_p]);
    pos.x += 30;
    sfText_setPosition(inv->prompttext, pos);
    set_string(inv, item, 2);
    sfRenderWindow_drawText(GET_WINDOW, inv->prompttext, NULL);
    pos = sfSprite_getPosition(STATUS_SPRITE[spe_p]);
    pos.x += 30;
    sfText_setPosition(inv->prompttext, pos);
    set_string(inv, item, 3);
    sfRenderWindow_drawText(GET_WINDOW, inv->prompttext, NULL);
}

void display_texts(game_t *game, inventory_t *inv, item_t *item)
{
    sfVector2f pos = sfSprite_getPosition(inv->promptsprite);
    float xbase = pos.x;

    sfText_setString(inv->prompttext, item->name);
    pos.x += 90 - (bstrlen(item->name) * 4);
    sfText_setPosition(inv->prompttext, pos);
    sfRenderWindow_drawText(GET_WINDOW, inv->prompttext, NULL);
    sfText_setString(inv->prompttext, item->description);
    pos.x = xbase + 20;
    pos.y += 20;
    sfText_setCharacterSize(inv->prompttext, 10);
    sfText_setColor(inv->prompttext, sfYellow);
    sfText_setPosition(inv->prompttext, pos);
    sfRenderWindow_drawText(GET_WINDOW, inv->prompttext, NULL);
    sfText_setCharacterSize(inv->prompttext, 15);
    display_stats_texts(game, inv, item);
}

void set_prompt_pos(inventory_t *inv)
{
    sfVector2f pos = sfSprite_getPosition(inv->selecsprite);
    pos.x = pos.x - 57.f;
    pos.y = pos.y - 82.f;
    sfSprite_setPosition(inv->promptsprite, pos);
}

void display_prompt(inventory_t *inv, game_t *game)
{
    set_prompt_pos(inv);
    sfRenderWindow_drawSprite(GET_WINDOW, inv->promptsprite, NULL);
    display_stats_sprites(inv, game);
    display_texts(game, inv, get_selected_item(inv));
}