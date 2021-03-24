/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_mons_t data_mons[] = {
    {'a', 130, 255, 60, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 5, "abc"},
    {'b', 150, 230, 255, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 8, "ade"},
    {'c', 150, 0, 170, 255, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 7, "afg"},
    {'d', 150, 255, 255, 255, SLIME_IMG, SLIME_IMG_COLOR, 66, 50, 3, 2, "abc"}
};

int find_in_mons_database(char name)
{
    for (int i = 0; i < 4; i++)
        if (data_mons[i].name == name)
            return i;
    return 0;
}

void init_mons_texture(mons_t *element, sfVector2f pos, int i)
{
    element->texture = malloc(sizeof(mons_texture_t));
    element->texture->rect = (sfIntRect){0, 0, data_mons[i].width, data_mons[i].height};
    element->texture->nb_anim = data_mons[i].nb_anim;
    element->texture->texture = sfTexture_createFromFile(data_mons[i].sprite, NULL);
    element->texture->sprite = sfSprite_create();
    element->texture->texture_color = sfTexture_createFromFile(data_mons[i].sprite_color, NULL);
    element->texture->sprite_color = sfSprite_create();
    sfSprite_setOrigin(element->texture->sprite, (sfVector2f){element->texture->rect.width / 2, element->texture->rect.height});
    sfSprite_setOrigin(element->texture->sprite_color, (sfVector2f){element->texture->rect.width / 2, element->texture->rect.height});
    sfSprite_setPosition(element->texture->sprite, pos);
    sfSprite_setPosition(element->texture->sprite_color, pos);
    sfSprite_setColor(element->texture->sprite_color, sfColor_fromRGB(data_mons[i].red, data_mons[i].green, data_mons[i].blue));
}

void init_mons_stat(mons_t *elem, sfVector2f pos, int i)
{
    elem->stat = malloc(sizeof(mons_stat_t));
    MONS_MAX_HP(elem) = data_mons[i].hp;
    MONS_CURR_HP(elem) = MONS_MAX_HP(elem);
    MONS_HP(elem) = sfRectangleShape_create();
    sfRectangleShape_setOrigin(MONS_HP(elem), (sfVector2f){elem->texture->rect.width / 2 + 50, 0});
    sfRectangleShape_setSize(MONS_HP(elem), (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(MONS_HP(elem), sfGreen);
    sfRectangleShape_setPosition(MONS_HP(elem), (sfVector2f){pos.x + elem->texture->rect.width / 2, pos.y + 10});
    MONS_SPEED(elem) = data_mons[i].speed;
    MONS_CURR_ATB(elem) = 0;
    elem->stat->atb = sfRectangleShape_create();
    sfRectangleShape_setOrigin(elem->stat->atb, (sfVector2f){elem->texture->rect.width / 2 + 50, 0});
    sfRectangleShape_setSize(elem->stat->atb, (sfVector2f){0, 10});
    sfRectangleShape_setFillColor(elem->stat->atb, sfCyan);
    sfRectangleShape_setPosition(elem->stat->atb, (sfVector2f){pos.x + elem->texture->rect.width / 2, pos.y + 30});
}

void put_in_mons_list(mons_t **mons, sfVector2f pos, char name, game_t *game)
{
    mons_t *elem = malloc(sizeof(mons_t));
    mons_t *last = *mons;
    int i = find_in_mons_database(name);

    init_mons_texture(elem, pos, i);
    init_mons_stat(elem, pos, i);
    elem->skill = NULL;
    for (int j = 0; data_mons[i].skill[j]; j++)
        put_in_skill_list(&elem->skill, data_mons[i].skill[j], game);
    elem->next = NULL;

    if (*mons == NULL) {
        elem->next = *mons;
        *mons = elem;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = elem;
    }
}
