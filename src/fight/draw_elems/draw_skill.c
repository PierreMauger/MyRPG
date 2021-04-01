/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_skill_desc(skill_t *temp, game_t *game, int x)
{
    if (check_collide_skill(game, temp)) {
        sfText_setPosition(temp->desc->text, (sfVector2f){x + 40, 640});
        sfText_setPosition(temp->desc->cd_text, (sfVector2f){x + 40, 680});
        sfText_setPosition(temp->desc->name_text, (sfVector2f){x + 40, 620});
        sfText_setString(temp->desc->cd_text, bitoa(temp->stat->act_cd));
        sfSprite_setPosition(temp->desc->sprite, (sfVector2f){x, 700});
        sfRenderWindow_drawSprite(GET_WINDOW, temp->desc->sprite, NULL);
        sfRenderWindow_drawText(GET_WINDOW, temp->desc->text, NULL);
        sfRenderWindow_drawText(GET_WINDOW, temp->desc->name_text, NULL);
        if (temp->stat->act_cd != 0)
            sfRenderWindow_drawText(GET_WINDOW, temp->desc->cd_text, NULL);
    }
}

void draw_skill(game_t *game)
{
    int x = 1100;

    for (skill_t *temp = game->ind->ptr_mons->skill; temp; temp = temp->next) {
        sfSprite_setPosition(temp->texture->sprite, (sfVector2f){x, 700});
        if (temp->stat->act_cd != 0)
            sfSprite_setColor(temp->texture->sprite, sfGrey);
        else
            sfSprite_setColor(temp->texture->sprite, sfWhite);
        if (temp == game->ind->ptr_skill)
            sfRenderWindow_drawSprite(GET_WINDOW, temp->texture->sprite,
            &RENDER_SKILL);
        else
            sfRenderWindow_drawSprite(GET_WINDOW, temp->texture->sprite, NULL);
        draw_skill_desc(temp, game, x);
        x += 100;
    }
}
