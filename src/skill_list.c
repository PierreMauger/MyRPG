/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', (int[]){40},      1, (int[]){0}, (int[]){0},  (float[]){-30}, 0, 1, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "-30% atb"},
    {'b', (int[]){30},      1, (int[]){0}, (int[]){1},    (float[]){0}, 0, 2, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "basic aoe"},
    {'c', (int[]){ 0},      1, (int[]){1}, (int[]){1},   (float[]){30}, 0, 3, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "speed boost"},
    {'d', (int[]){35, 50}, 2, (int[]){0, 0}, (int[]){0, 0},    (float[]){0, 0}, 0, 2, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "double hit"},
    {'e', (int[]){70, 0},   2, (int[]){0, 1}, (int[]){0, 1}, (float[]){0, 15}, 0, 1, GRASS_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "hit + boost\n  atb aoe"},
    {'f', (int[]){60},      1, (int[]){0}, (int[]){0},  (float[]){-50}, 0, 4, GRASS_IMG, BONK_IMG, 80, 80, 4, DIRT_IMG, "-50% atb"},
    {'g', (int[]){ 0},      1, (int[]){0}, (int[]){0},    (float[]){0}, 1, 5, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "attack one more\n time if atb = 0"},
    {'h', (int[]){80},      1, (int[]){0}, (int[]){0},    (float[]){0}, 0, 1, GRASS_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"}
};

int find_in_skill_database(char name)
{
    for (int i = 0; i < 8; i++)
        if (data_skill[i].name == name)
            return i;
    return 0;
}

void put_in_skill_list(skill_t **skill, char name, game_t *game)
{
    skill_t *element = malloc(sizeof(skill_t));
    skill_t *last = *skill;
    int i = find_in_skill_database(name);

    element->stat = malloc(sizeof(skill_stat_t));
    element->stat->name = data_skill[i].name;
    element->stat->nbr_hit = data_skill[i].nbr_hit;
    element->stat->coef = data_skill[i].coef;
    element->stat->target = data_skill[i].target;
    element->stat->aoe = data_skill[i].aoe;
    element->stat->atb_boost = data_skill[i].atb_boost;
    element->stat->passive = data_skill[i].passive;
    element->stat->ini_cd = data_skill[i].cooldown;
    element->stat->act_cd = 0;
    element->stat->anim_nb = data_skill[i].anim_nb;
    element->texture = malloc(sizeof(skill_texture_t));
    element->texture->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    element->texture->sprite = sfSprite_create();
    sfSprite_setTexture(element->texture->sprite, element->texture->texture, sfTrue);
    sfSprite_setPosition(element->texture->sprite, (sfVector2f){0, 0});
    element->anim = malloc(sizeof(skill_anim_t));
    element->anim->arect = (sfIntRect){0, 0, data_skill[i].anim_x, data_skill[i].anim_y};
    element->anim->atexture = sfTexture_createFromFile(data_skill[i].anim, NULL);
    element->anim->asprite = sfSprite_create();
    element->desc = malloc(sizeof(skill_desc_t));
    element->desc->dtexture = sfTexture_createFromFile(data_skill[i].desc_img, NULL);
    element->desc->dsprite = sfSprite_create();
    sfSprite_setTexture(element->desc->dsprite, element->desc->dtexture, sfTrue);
    sfSprite_setOrigin(element->desc->dsprite, (sfVector2f){0, 80});
    element->desc->text = sfText_create();
    sfText_setFont(element->desc->text, game->font);
    sfText_setCharacterSize(element->desc->text, 20);
    sfText_setString(element->desc->text, data_skill[i].desc);
    sfText_setColor(element->desc->text, sfWhite);
    sfText_setOrigin(element->desc->text, (sfVector2f){sfText_getGlobalBounds(element->desc->text).width / 2, 0});
    element->desc->cd_text = sfText_create();
    sfText_setFont(element->desc->cd_text, game->font);
    sfText_setCharacterSize(element->desc->cd_text, 20);
    sfText_setString(element->desc->cd_text, nbr_to_str(data_skill[i].cooldown));
    sfText_setColor(element->desc->cd_text, sfYellow);
    sfText_setOrigin(element->desc->cd_text, (sfVector2f){sfText_getGlobalBounds(element->desc->cd_text).width / 2, 0});
    element->next = NULL;

    if (*skill == NULL) {
        element->next = *skill;
        *skill = element;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = element;
    }
}
