/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/
//{'c', 150, 0, 170, 255, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 3, "ef"},
#include "game.h"

static data_mons_t data_mons[] = {
    {'a', 130, 255, 60, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 1.5, "abc"},
    {'b', 150, 230, 255, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 4, "ade"},
    {'c', 150, 0, 170, 255, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 3, "ef"},
    {'d', 100, 255, 0, 0, MONSTER_IMG, MONSTER_IMG_COLOR, 40, 80, 2, 3.5, "abc"}
};

int find_in_mons_database(char name)
{
    for (int i = 0; i < 4; i++)
        if (data_mons[i].name == name)
            return i;
    return 0;
}

void put_in_mons_list(mons_t **mons, sfVector2f pos, char name)
{
    mons_t *element = malloc(sizeof(mons_t));
    mons_t *last = *mons;
    int i = find_in_mons_database(name);

        //basic data
    element->height = data_mons[i].height;
    element->width = data_mons[i].width;
    element->nb_anim = data_mons[i].nb_anim;
    element->texture = sfTexture_createFromFile(data_mons[i].sprite, NULL);
    element->sprite = sfSprite_create();
    element->texture_color = sfTexture_createFromFile(data_mons[i].sprite_color, NULL);
    element->sprite_color = sfSprite_create();
    sfSprite_setOrigin(element->sprite, (sfVector2f){element->width / 2, element->height});
    sfSprite_setOrigin(element->sprite_color, (sfVector2f){element->width / 2, element->height});
    sfSprite_setPosition(element->sprite, pos);
    sfSprite_setPosition(element->sprite_color, pos);
    sfSprite_setColor(element->sprite_color, sfColor_fromRGB(data_mons[i].red, data_mons[i].green, data_mons[i].blue));
    element->rect = (sfIntRect){0, 0, element->width, element->height};

        //bars data
    element->max_hp = data_mons[i].hp;
    element->curr_hp = element->max_hp;
    element->hp = sfRectangleShape_create();
    sfRectangleShape_setOrigin(element->hp, (sfVector2f){element->width / 2 + 50, 0});
    sfRectangleShape_setSize(element->hp, (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(element->hp, sfGreen);
    sfRectangleShape_setPosition(element->hp, (sfVector2f){pos.x + element->width / 2, pos.y + 10});
    element->speed = data_mons[i].speed;
    element->atb_value = 0;
    element->atb = sfRectangleShape_create();
    sfRectangleShape_setOrigin(element->atb, (sfVector2f){element->width / 2 + 50, 0});
    sfRectangleShape_setSize(element->atb, (sfVector2f){0, 10});
    sfRectangleShape_setFillColor(element->atb, sfCyan);
    sfRectangleShape_setPosition(element->atb, (sfVector2f){pos.x + element->width / 2, pos.y + 30});

        //skill data
    element->skill = NULL;
    for (int j = 0; data_mons[i].skill[j]; j++)
        put_in_skill_list(&element->skill, data_mons[i].skill[j]);
    element->next = NULL;

    if (*mons == NULL) {
        element->next = *mons;
        *mons = element;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = element;
    }
}
