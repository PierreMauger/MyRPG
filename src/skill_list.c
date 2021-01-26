/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', 10, 0, 0, DIRT_IMG},
    {'b', 20, 1, 0, DIRT_IMG},
    {'c', 30, 0, 0, DIRT_IMG},
    {'d', 40, 0, 0, DIRT_IMG},
    {'e', 50, 0, 1, GRASS_IMG},
    {'f', 60, 0, 0, GRASS_IMG},
    {'g', 70, 0, 0, GRASS_IMG},
    {'h', 80, 0, 0, GRASS_IMG}
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

    element->coef = data_skill[i].coef;
    element->target = data_skill[i].target;
    element->aoe = data_skill[i].aoe;
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
