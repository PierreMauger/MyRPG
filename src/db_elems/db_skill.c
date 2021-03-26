/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {"Morsure", (int[]){40},      1, (int[]){0}, (int[]){0},  (float[]){-30}, 0, 1, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "-30% atb"},
    {"AOE", (int[]){30},      1, (int[]){0}, (int[]){1},    (float[]){0}, 0, 2, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "basic aoe"},
    {"Ralliement", (int[]){ 0},      1, (int[]){1}, (int[]){1},   (float[]){30}, 0, 3, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "speed boost"},
    {"Ruee sauvage", (int[]){35, 50}, 2, (int[]){0, 0}, (int[]){0, 0},    (float[]){0, 0}, 0, 3, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "double hit"},
    {"Course", (int[]){70, 0},   2, (int[]){0, 1}, (int[]){0, 1}, (float[]){0, 15}, 0, 4, GRASS_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "hit + boost\n  atb aoe"},
    {"Belier", (int[]){60},      1, (int[]){0}, (int[]){0},  (float[]){-50}, 0, 4, GRASS_IMG, BONK_IMG, 80, 80, 4, DIRT_IMG, "-50% atb"},
    {"Chasseur", (int[]){ 0},      1, (int[]){0}, (int[]){0},    (float[]){0}, 1, 5, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "attack one more\n time if atb = 0"},
    {"lol", (int[]){80},      1, (int[]){0}, (int[]){0},    (float[]){0}, 0, 1, GRASS_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"}
};

int find_in_skill_database(char *name)
{
    for (int i = 0; i < 8; i++)
        if (!my_strcmp(data_skill[i].name, name))
            return i;
    return 0;
}

void init_skill_stat(skill_t *elem, int i)
{
    elem->stat = malloc(sizeof(skill_stat_t));
    elem->stat->name = data_skill[i].name;
    elem->stat->nbr_hit = data_skill[i].nbr_hit;
    elem->stat->coef = data_skill[i].coef;
    elem->stat->target = data_skill[i].target;
    elem->stat->aoe = data_skill[i].aoe;
    elem->stat->atb_boost = data_skill[i].atb_boost;
    elem->stat->passive = data_skill[i].passive;
    elem->stat->ini_cd = data_skill[i].cooldown;
    elem->stat->act_cd = 0;
    elem->stat->anim_nb = data_skill[i].anim_nb;
}

void init_skill_texture(skill_t *elem, int i)
{
    elem->texture = malloc(sizeof(skill_texture_t));
    elem->texture->texture = sfTexture_createFromFile(
    data_skill[i].sprite, NULL);
    elem->texture->sprite = sfSprite_create();
    sfSprite_setTexture(elem->texture->sprite, elem->texture->texture, sfTrue);
    sfSprite_setPosition(elem->texture->sprite, (sfVector2f){0, 0});
}

void init_skill_anim(skill_t *elem, int i)
{
    elem->anim = malloc(sizeof(skill_anim_t));
    elem->anim->rect = (sfIntRect){0, 0, data_skill[i].anim_x,
    data_skill[i].anim_y};
    elem->anim->texture = sfTexture_createFromFile(data_skill[i].anim, NULL);
    elem->anim->sprite = sfSprite_create();
}

void init_skill_desc(skill_t *elem, game_t *game, int i)
{
    elem->desc = malloc(sizeof(skill_desc_t));
    elem->desc->texture = sfTexture_createFromFile(data_skill[i].desc_img,
    NULL);
    elem->desc->sprite = sfSprite_create();
    sfSprite_setTexture(elem->desc->sprite, elem->desc->texture, sfTrue);
    sfSprite_setOrigin(elem->desc->sprite, (sfVector2f){0, 80});
    elem->desc->text = init_text(game, data_skill[i].desc, sfWhite);
    elem->desc->cd_text = init_text(game, nbr_to_str(data_skill[i].cooldown),
    sfYellow);
    elem->desc->name_text = init_text(game, data_skill[i].name, sfYellow);
}
