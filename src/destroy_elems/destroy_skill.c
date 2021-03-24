/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_skill(skill_t *skill)
{
    skill_t *temp = NULL;

    while (skill != NULL) {
        temp = skill;
        sfTexture_destroy(skill->texture->texture);
        sfSprite_destroy(skill->texture->sprite);
        sfTexture_destroy(skill->anim->atexture);
        sfSprite_destroy(skill->anim->asprite);
        sfTexture_destroy(skill->desc->dtexture);
        sfSprite_destroy(skill->desc->dsprite);
        sfText_destroy(skill->desc->text);
        sfText_destroy(skill->desc->cd_text);
        skill = skill->next;
        free(temp);
    }
}
