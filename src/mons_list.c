/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void put_in_p_mons_list(p_mons_t **p_mons, sfVector2f pos)
{
    p_mons_t *element = malloc(sizeof(p_mons_t));

    element->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *p_mons;
    *p_mons = element;
}

void put_in_e_mons_list(e_mons_t **e_mons, sfVector2f pos)
{
    e_mons_t *element = malloc(sizeof(e_mons_t));

    element->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *e_mons;
    *e_mons = element;
}