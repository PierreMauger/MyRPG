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

void init_mons_texture(mons_t *elem, sfVector2f pos, int i)
{
    elem->texture = malloc(sizeof(mons_texture_t));
    elem->texture->rect = (sfIntRect){0, 0, data_mons[i].width,
    data_mons[i].height};
    elem->texture->nb_anim = data_mons[i].nb_anim;
    elem->texture->texture = sfTexture_createFromFile(
    data_mons[i].sprite, NULL);
    MONS_SPRITE(elem) = sfSprite_create();
    elem->texture->texture_color = sfTexture_createFromFile(
    data_mons[i].sprite_color, NULL);
    MONS_SPRITE_COLOR(elem) = sfSprite_create();
    sfSprite_setOrigin(MONS_SPRITE(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2, MONS_HEIGHT(elem)});
    sfSprite_setOrigin(MONS_SPRITE_COLOR(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2, MONS_HEIGHT(elem)});
    sfSprite_setPosition(MONS_SPRITE(elem), pos);
    sfSprite_setPosition(MONS_SPRITE_COLOR(elem), pos);
    sfSprite_setColor(MONS_SPRITE_COLOR(elem), sfColor_fromRGB(
    data_mons[i].red, data_mons[i].green, data_mons[i].blue));
}

void init_mons_stat(mons_t *elem, sfVector2f pos, int i)
{
    elem->stat = malloc(sizeof(mons_stat_t));
    MONS_MAX_HP(elem) = data_mons[i].hp;
    MONS_CURR_HP(elem) = MONS_MAX_HP(elem);
    MONS_HP(elem) = sfRectangleShape_create();
    sfRectangleShape_setOrigin(MONS_HP(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2+ 50, 0});
    sfRectangleShape_setSize(MONS_HP(elem), (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(MONS_HP(elem), sfGreen);
    sfRectangleShape_setPosition(MONS_HP(elem),
    (sfVector2f){pos.x + MONS_WIDTH(elem) / 2, pos.y + 10});
    MONS_SPEED(elem) = data_mons[i].speed;
    MONS_CURR_ATB(elem) = 0;
    elem->stat->atb = sfRectangleShape_create();
    sfRectangleShape_setOrigin(elem->stat->atb,
    (sfVector2f){MONS_WIDTH(elem) / 2 + 50, 0});
    sfRectangleShape_setSize(elem->stat->atb, (sfVector2f){0, 10});
    sfRectangleShape_setFillColor(elem->stat->atb, sfCyan);
    sfRectangleShape_setPosition(elem->stat->atb,
    (sfVector2f){pos.x + MONS_WIDTH(elem) / 2, pos.y + 30});
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
        put_in_skill_list(&elem->skill, game, data_mons[i].skill[j]);
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
