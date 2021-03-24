/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;
    int x = 1400;

    while (temp != NULL) {
        sfSprite_setPosition(temp->texture->sprite, (sfVector2f){x, 900});
        sfText_setPosition(temp->desc->text, (sfVector2f){x + 40, 860});
        sfText_setPosition(temp->desc->cd_text, (sfVector2f){x + 40, 880});
        if (temp->stat->act_cd != 0)
            sfSprite_setColor(temp->texture->sprite, sfColor_fromRGB(128, 128, 128));
        else
            sfSprite_setColor(temp->texture->sprite, sfColor_fromRGB(255, 255, 255));
        sfRenderWindow_drawSprite(game->window->window, temp->texture->sprite, NULL);
        sfSprite_setPosition(temp->desc->dsprite, (sfVector2f){x, 900});
        sfText_setString(temp->desc->cd_text, nbr_to_str(temp->stat->act_cd));
        if (check_collide_skill(game, temp)) {
            sfRenderWindow_drawSprite(game->window->window, temp->desc->dsprite, NULL);
            sfRenderWindow_drawText(game->window->window, temp->desc->text, NULL);
            if (temp->stat->act_cd != 0)
                sfRenderWindow_drawText(game->window->window, temp->desc->cd_text, NULL);
        }
        temp = temp->next;
        x += 100;
    }
}
