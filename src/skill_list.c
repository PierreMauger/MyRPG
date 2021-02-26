/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', 40, 0, 0,  -30, 0, 1, DIRT_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'b', 30, 0, 1,    0, 0, 2, DIRT_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'c',  0, 1, 1,   30, 0, 3, DIRT_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'d', 50, 0, 0,    0, 0, 2, DIRT_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'e', 60, 0, 0, -100, 0, 1, GRASS_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'f', 60, 0, 0,  -50, 0, 4, GRASS_IMG, BONK_IMG, DIRT_IMG, "lol"},
    {'g',  0, 0, 0,    0, 1, 5, DIRT_IMG, SLASH_IMG, DIRT_IMG, "lol"},
    {'h', 80, 0, 0,    0, 0, 1, GRASS_IMG, SLASH_IMG, DIRT_IMG, "lol"}
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
    element->coef = data_skill[i].coef;
    element->target = data_skill[i].target;
    element->aoe = data_skill[i].aoe;
    element->atb_boost = data_skill[i].atb_boost;
    element->passive = data_skill[i].passive;
    element->ini_cd = data_skill[i].cooldown;
    element->act_cd = 0;
    element->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, (sfVector2f){0, 0});
    element->arect = (sfIntRect){0, 0, 80, 80};
    element->atexture = sfTexture_createFromFile(data_skill[i].anim, NULL);
    element->asprite = sfSprite_create();
    element->dtexture = sfTexture_createFromFile(data_skill[i].desc_img, NULL);
    element->dsprite = sfSprite_create();
    sfSprite_setTexture(element->dsprite, element->dtexture, sfTrue);
    sfSprite_setOrigin(element->dsprite, (sfVector2f){0, 80});
    element->text = sfText_create();
    sfText_setFont(element->text, game->font);
    sfText_setCharacterSize(element->text, 20);
    sfText_setString(element->text, data_skill[i].desc);
    sfText_setColor(element->text, sfWhite);
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
