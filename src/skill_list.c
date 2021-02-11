/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', 40, 0, 0,  -30, 0, DIRT_IMG},
    {'b', 30, 0, 1,    0, 0, DIRT_IMG},
    {'c',  0, 1, 1,   30, 0, DIRT_IMG},
    {'d', 50, 0, 0,    0, 0, DIRT_IMG},
    {'e', 60, 0, 0, -100, 0, GRASS_IMG},
    {'f', 60, 0, 0,  -50, 0, GRASS_IMG},
    {'g',  0, 0, 0,    0, 1, DIRT_IMG},
    {'h', 80, 0, 0,    0, 0, GRASS_IMG}
};

int find_in_skill_database(char name)
{
    for (int i = 0; i < 8; i++)
        if (data_skill[i].name == name)
            return i;
    return 0;
}

void put_in_skill_list(skill_t **skill, char name)
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
    element->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, (sfVector2f){0, 0});
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
