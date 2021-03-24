/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_skill(skill_t *skill)
{
    while (skill != NULL) {
        sfTexture_destroy(skill->texture);
        sfSprite_destroy(skill->sprite);
        sfTexture_destroy(skill->atexture);
        sfSprite_destroy(skill->asprite);
        sfTexture_destroy(skill->dtexture);
        sfSprite_destroy(skill->dsprite);
        sfText_destroy(skill->text);
        sfText_destroy(skill->cd_text);
        skill = skill->next;
    }
}
