/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_skill_texture(skill_texture_t *texture)
{
    sfTexture_destroy(texture->texture);
    sfSprite_destroy(texture->sprite);
    free(texture);
}

void destroy_skill_anim(skill_anim_t *anim)
{
    sfTexture_destroy(anim->texture);
    sfSprite_destroy(anim->sprite);
    free(anim);
}

void destroy_skill_stat(skill_stat_t *stat)
{
    free(stat->name);
    free(stat->coef);
    free(stat->target);
    free(stat->aoe);
    free(stat->atb_boost);
    free(stat->status);
    free(stat->status_turn);
    free(stat);
}

void destroy_skill_desc(skill_desc_t *desc)
{
    sfTexture_destroy(desc->texture);
    sfSprite_destroy(desc->sprite);
    sfText_destroy(desc->text);
    sfText_destroy(desc->cd_text);
    sfText_destroy(desc->name_text);
    free(desc);
}

void destroy_skill(skill_t *skill)
{
    skill_t *temp = NULL;

    while (skill != NULL) {
        temp = skill;
        destroy_skill_texture(skill->texture);
        destroy_skill_anim(skill->anim);
        destroy_skill_stat(skill->stat);
        destroy_skill_desc(skill->desc);
        skill = skill->next;
        free(temp);
    }
}
