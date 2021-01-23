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

    element->texture = sfTexture_createFromFile(MONSTER_IMG, NULL);
    element->sprite = sfSprite_create();
    element->texture_color = sfTexture_createFromFile(MONSTER_IMG_COLOR, NULL);
    element->sprite_color = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setTexture(element->sprite_color, element->texture_color, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    sfSprite_setPosition(element->sprite_color, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *p_mons;
    *p_mons = element;
}

void put_in_e_mons_list(e_mons_t **e_mons, sfVector2f pos)
{
    e_mons_t *element = malloc(sizeof(e_mons_t));

    element->texture = sfTexture_createFromFile(GRASS_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *e_mons;
    *e_mons = element;
}

void change_color(game_t *game, sfColor color)
{
    p_mons_t *temp = game->p_mons;

    while (temp != NULL) {
        sfSprite_setColor(temp->sprite_color, color);
        temp = temp->next;
    }
}