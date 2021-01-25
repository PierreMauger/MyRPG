/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_skill_t data_skill[] = {
    {'a', 50, DIRT_IMG},
    {'b', 100, GRASS_IMG}
};

int find_in_skill_database(char name)
{
    for (int i = 0; i < 4; i++)
        if (data_skill[i].name == name)
            return i;
    return 0;
}

void put_in_skill_list(skill_t **skill, char name)
{
    skill_t *element = malloc(sizeof(skill_t));
    int i = find_in_skill_database(name);

    element->coef = data_skill[i].coef;
    element->texture = sfTexture_createFromFile(data_skill[i].sprite, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, (sfVector2f){0, 0});

    element->next = *skill;
    *skill = element;
}
