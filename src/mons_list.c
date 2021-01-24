/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_mons_t data_mons[] = {
    {'a', 100, 255, 0, 0, MONSTER_IMG, MONSTER_IMG_COLOR},
    {'b', 150, 0, 255, 0, MONSTER_IMG, MONSTER_IMG_COLOR},
    {'c', 150, 0, 0, 255, MONSTER_IMG, MONSTER_IMG_COLOR}
};

int find_in_database(char name)
{
    for (int i = 0; i < 3; i++)
        if (data_mons[i].name == name)
            return i;
    return 0;
}

void put_in_mons_list(mons_t **mons, sfVector2f pos, char name)
{
    mons_t *element = malloc(sizeof(mons_t));
    int i = find_in_database(name);

    element->texture = sfTexture_createFromFile(data_mons[i].sprite, NULL);
    element->sprite = sfSprite_create();
    element->texture_color = sfTexture_createFromFile(data_mons[i].sprite_color, NULL);
    element->sprite_color = sfSprite_create();
    sfSprite_setOrigin(element->sprite, (sfVector2f){20, 40});
    sfSprite_setOrigin(element->sprite_color, (sfVector2f){20, 40});
    sfSprite_setPosition(element->sprite, pos);
    sfSprite_setPosition(element->sprite_color, pos);
    sfSprite_setColor(element->sprite_color, sfColor_fromRGB(data_mons[i].red, data_mons[i].green, data_mons[i].blue));
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *mons;
    *mons = element;
}
