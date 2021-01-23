/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_mons_t data_mons[] = {
    {'a', 100, 255, 0, 0, MONSTER_IMG, MONSTER_IMG_COLOR},
    {'b', 150, 0, 255, 0, MONSTER_IMG, DIRT_IMG},
    {'c', 150, 0, 0, 255, MONSTER_IMG, MONSTER_IMG_COLOR}
};

int find_in_database(char name)
{
    for (int i = 0; i < 3; i++)
        if (data_mons[i].name == name)
            return i;
    return 0;
}

void put_in_p_mons_list(p_mons_t **p_mons, sfVector2f pos, char name)
{
    p_mons_t *element = malloc(sizeof(p_mons_t));
    int i = find_in_database(name);

    element->texture = sfTexture_createFromFile(data_mons[i].sprite, NULL);
    element->sprite = sfSprite_create();
    element->texture_color = sfTexture_createFromFile(data_mons[i].sprite_color, NULL);
    element->sprite_color = sfSprite_create();
    sfSprite_setPosition(element->sprite, pos);
    sfSprite_setPosition(element->sprite_color, pos);
    sfSprite_setColor(element->sprite_color, sfColor_fromRGB(data_mons[i].red, data_mons[i].green, data_mons[i].blue));
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *p_mons;
    *p_mons = element;
}

void put_in_e_mons_list(e_mons_t **e_mons, sfVector2f pos)
{
    e_mons_t *element = malloc(sizeof(e_mons_t));

    element->texture = sfTexture_createFromFile(GRASS_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *e_mons;
    *e_mons = element;
}
