/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_skill_stat(skill_t *elem, char *buffer, int id)
{
    elem->stat = malloc(sizeof(skill_stat_t));
    elem->stat->name = (char *)parser(buffer, "name", id);
    elem->stat->nb_hit = (int)parser(buffer, "nb_hit", id);
    elem->stat->coef = (int *)parser(buffer, "coef", id);
    elem->stat->target = (int *)parser(buffer, "target", id);
    elem->stat->aoe = (int *)parser(buffer, "aoe", id);
    elem->stat->atb_boost = (float *)parser(buffer, "atb_boost", id);
    elem->stat->passive = (int)parser(buffer, "passive", id);
    elem->stat->ini_cd = (int)parser(buffer, "cooldown", id);
    elem->stat->act_cd = 0;
    elem->stat->nb_anim = (int)parser(buffer, "nb_anim", id);
}

void init_skill_texture(skill_t *elem, char *buffer, int id)
{
    elem->texture = malloc(sizeof(skill_texture_t));
    elem->texture->texture = sfTexture_createFromFile(
    (char *)parser(buffer, "img", id), NULL);
    elem->texture->sprite = sfSprite_create();
    sfTexture_setSmooth(elem->texture->texture, sfTrue);
    sfSprite_setTexture(elem->texture->sprite, elem->texture->texture, sfTrue);
    sfSprite_setPosition(elem->texture->sprite, (sfVector2f){0, 0});
}

void init_skill_anim(skill_t *elem, char *buffer, int id)
{
    elem->anim = malloc(sizeof(skill_anim_t));
    elem->anim->rect = (sfIntRect){0, 0, (int)parser(buffer, "anim_x", id),
    (int)parser(buffer, "anim_y", id)};
    elem->anim->texture = sfTexture_createFromFile((char *)parser(buffer,
    "anim", id), NULL);
    elem->anim->sprite = sfSprite_create();
}

void init_skill_desc(game_t *game, skill_t *elem, char *buffer, int id)
{
    elem->desc = malloc(sizeof(skill_desc_t));
    elem->desc->texture = sfTexture_createFromFile((char *)parser(buffer,
    "desc_img", id), NULL);
    elem->desc->sprite = sfSprite_create();
    sfSprite_setTexture(elem->desc->sprite, elem->desc->texture, sfTrue);
    sfSprite_setOrigin(elem->desc->sprite, (sfVector2f){0, 80});
    elem->desc->text = init_text(game, (char *)parser(buffer, "desc", id),
    sfWhite);
    elem->desc->cd_text = init_text(game, bitoa((int)parser(buffer,
    "cooldown", id)),sfYellow);
    elem->desc->name_text = init_text(game, (char *)parser(buffer, "name",
    id), sfYellow);
}
