/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide_skill(game_t *game, skill_t *skill)
{
    sfVector2f skill_pos = sfSprite_getPosition(skill->sprite);

    if (game->mouse_pos.x > skill_pos.x && game->mouse_pos.x < skill_pos.x + 80 && game->mouse_pos.y > skill_pos.y && game->mouse_pos.y < skill_pos.y + 80)
        return 1;
    return 0;
}

void choose_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;

    while (temp != NULL) {
        if (check_collide_skill(game, temp) == 1)
            if (temp->passive == 0 && temp->act_cd == 0)
                game->ind->ptr_skill = temp;
        temp = temp->next;
    }
}

void draw_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;
    int x = 1400;

    while (temp != NULL) {
        sfSprite_setPosition(temp->sprite, (sfVector2f){x, 900});
        sfText_setPosition(temp->text, (sfVector2f){x + 40, 860});
        sfText_setPosition(temp->cd_text, (sfVector2f){x + 40, 880});
        if (temp->act_cd != 0)
            sfSprite_setColor(temp->sprite, sfColor_fromRGB(128, 128, 128));
        else
            sfSprite_setColor(temp->sprite, sfColor_fromRGB(255, 255, 255));
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        sfSprite_setPosition(temp->dsprite, (sfVector2f){x, 900});
        sfText_setString(temp->cd_text, nbr_to_str(temp->act_cd));
        if (check_collide_skill(game, temp)) {
            sfRenderWindow_drawSprite(game->window, temp->dsprite, NULL);
            sfRenderWindow_drawText(game->window, temp->text, NULL);
            if (temp->act_cd != 0)
                sfRenderWindow_drawText(game->window, temp->cd_text, NULL);
        }
        temp = temp->next;
        x += 100;
    }
}
