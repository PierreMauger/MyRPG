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
        sfText_setPosition(temp->desc->text, (sfVector2f){x + 40, 840});
        sfText_setPosition(temp->desc->cd_text, (sfVector2f){x + 40, 880});
        sfText_setPosition(temp->desc->name_text, (sfVector2f){x + 40, 820});
        sfText_setString(temp->desc->cd_text, nbr_to_str(temp->stat->act_cd));
        sfSprite_setPosition(temp->desc->sprite, (sfVector2f){x, 900});
        sfRenderWindow_drawSprite(GET_WINDOW, temp->desc->sprite, NULL);
        sfRenderWindow_drawText(GET_WINDOW, temp->desc->text, NULL);
        sfRenderWindow_drawText(GET_WINDOW, temp->desc->name_text, NULL);
        if (temp->stat->act_cd != 0)
            sfRenderWindow_drawText(GET_WINDOW, temp->desc->cd_text, NULL);
    }
}

void draw_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;
    int x = 1400;

    while (temp != NULL) {
        sfSprite_setPosition(temp->texture->sprite, (sfVector2f){x, 900});
        if (temp->stat->act_cd != 0)
            sfSprite_setColor(temp->texture->sprite, sfGrey);
        else
            sfSprite_setColor(temp->texture->sprite, sfWhite);
        if (temp == game->ind->ptr_skill)
            sfRenderWindow_drawSprite(GET_WINDOW, temp->texture->sprite,
            &game->render);
        else
            sfRenderWindow_drawSprite(GET_WINDOW, temp->texture->sprite, NULL);
        draw_skill_desc(temp, game, x);
        temp = temp->next;
        x += 100;
    }
}
