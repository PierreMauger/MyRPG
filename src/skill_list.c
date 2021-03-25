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
    elem->texture->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    elem->texture->sprite = sfSprite_create();
    sfSprite_setTexture(elem->texture->sprite, elem->texture->texture, sfTrue);
    sfSprite_setPosition(elem->texture->sprite, (sfVector2f){0, 0});
}

void init_skill_anim(skill_t *elem, int i)
{
    elem->anim = malloc(sizeof(skill_anim_t));
    elem->anim->rect = (sfIntRect){0, 0, data_skill[i].anim_x, data_skill[i].anim_y};
    elem->anim->texture = sfTexture_createFromFile(data_skill[i].anim, NULL);
    elem->anim->sprite = sfSprite_create();
}

void init_skill_desc(skill_t *elem, game_t *game, int i)
{
    elem->desc = malloc(sizeof(skill_desc_t));
    elem->desc->texture = sfTexture_createFromFile(data_skill[i].desc_img, NULL);
    elem->desc->sprite = sfSprite_create();
    sfSprite_setTexture(elem->desc->sprite, elem->desc->texture, sfTrue);
    sfSprite_setOrigin(elem->desc->sprite, (sfVector2f){0, 80});
    elem->desc->text = sfText_create();
    sfText_setFont(elem->desc->text, game->font);
    sfText_setCharacterSize(elem->desc->text, 20);
    sfText_setString(elem->desc->text, data_skill[i].desc);
    sfText_setColor(elem->desc->text, sfWhite);
    sfText_setOrigin(elem->desc->text, (sfVector2f){sfText_getGlobalBounds(elem->desc->text).width / 2, 0});
    elem->desc->cd_text = sfText_create();
    sfText_setFont(elem->desc->cd_text, game->font);
    sfText_setCharacterSize(elem->desc->cd_text, 20);
    sfText_setString(elem->desc->cd_text, nbr_to_str(data_skill[i].cooldown));
    sfText_setColor(elem->desc->cd_text, sfYellow);
    sfText_setOrigin(elem->desc->cd_text, (sfVector2f){sfText_getGlobalBounds(elem->desc->cd_text).width / 2, 0});
}

void put_in_skill_list(skill_t **skill, game_t *game, char name)
{
    skill_t *elem = malloc(sizeof(skill_t));
    skill_t *last = *skill;
    int i = find_in_skill_database(name);

    init_skill_stat(elem, i);
    init_skill_texture(elem, i);
    init_skill_anim(elem, i);
    init_skill_desc(elem, game, i);
    elem->next = NULL;
    if (*skill == NULL) {
        elem->next = *skill;
        *skill = elem;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = elem;
    }
}
