/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', (int[]){40},      1, (int[]){0}, (int[]){0},  (float[]){-30}, 0, 1, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
    {'b', (int[]){30},      1, (int[]){0}, (int[]){1},    (float[]){0}, 0, 2, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
    {'c', (int[]){ 0},      1, (int[]){1}, (int[]){1},   (float[]){30}, 0, 3, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
    {'d', (int[]){50, 100}, 2, (int[]){0, 0}, (int[]){0, 0},    (float[]){0, 0}, 0, 2, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
    {'e', (int[]){70, 0},   2, (int[]){0, 1}, (int[]){0, 1}, (float[]){0, 100}, 0, 1, GRASS_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
    {'f', (int[]){60},      1, (int[]){0}, (int[]){0},  (float[]){-50}, 0, 4, GRASS_IMG, BONK_IMG, 80, 80, 4, DIRT_IMG, "lol"},
    {'g', (int[]){ 0},      1, (int[]){0}, (int[]){0},    (float[]){0}, 1, 5, DIRT_IMG, SLASH_IMG, 32, 88, 4, DIRT_IMG, "lol"},
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

    element->name = data_skill[i].name;
    element->nbr_hit = data_skill[i].nbr_hit;
    element->coef = malloc(sizeof(int) * (element->nbr_hit + 1));
    element->coef = data_skill[i].coef;
    element->target = data_skill[i].target;
    element->aoe = data_skill[i].aoe;
    element->atb_boost = data_skill[i].atb_boost;
    element->passive = data_skill[i].passive;
    element->ini_cd = data_skill[i].cooldown;
    element->act_cd = 0;
    element->anim_nb = data_skill[i].anim_nb;
    element->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, (sfVector2f){0, 0});
    element->arect = (sfIntRect){0, 0, data_skill[i].anim_x, data_skill[i].anim_y};
    element->atexture = sfTexture_createFromFile(data_skill[i].anim, NULL);
    element->asprite = sfSprite_create();
    element->dtexture = sfTexture_createFromFile(data_skill[i].desc_img, NULL);
    element->dsprite = sfSprite_create();
    sfSprite_setTexture(element->dsprite, element->dtexture, sfTrue);
    sfSprite_setOrigin(element->dsprite, (sfVector2f){0, 80});
    element->text = sfText_create();
    sfText_setFont(element->text, game->font);
    sfText_setCharacterSize(element->text, 20);
    sfText_setString(element->text, nbr_to_str(data_skill[i].coef[0]));
    sfText_setColor(element->text, sfWhite);
    sfText_setOrigin(element->text, (sfVector2f){sfText_getGlobalBounds(element->text).width / 2, 0});
    element->cd_text = sfText_create();
    sfText_setFont(element->cd_text, game->font);
    sfText_setCharacterSize(element->cd_text, 20);
    sfText_setString(element->cd_text, nbr_to_str(data_skill[i].cooldown));
    sfText_setColor(element->cd_text, sfYellow);
    sfText_setOrigin(element->cd_text, (sfVector2f){sfText_getGlobalBounds(element->text).width / 2, 0});
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
