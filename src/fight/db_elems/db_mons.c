/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_mons_pos(mons_t *mons, sfVector2f pos)
{
    sfSprite_setPosition(MONS_SPRITE(mons), pos);
    sfSprite_setPosition(MONS_SPRITE_COLOR(mons), pos);

    sfRectangleShape_setPosition(MONS_HP(mons),
    (sfVector2f){pos.x + MONS_WIDTH(mons) / 2, pos.y + 10});
    sfRectangleShape_setPosition(mons->stat->atb,
    (sfVector2f){pos.x + MONS_WIDTH(mons) / 2, pos.y + 30});
}

void init_mons_texture(mons_t *elem, char *buffer, int i)
{
    elem->texture = malloc(sizeof(mons_texture_t));
    elem->texture->rect = (sfIntRect){0, 0, (int)parser(buffer, "width", i),
    (int)parser(buffer, "height", i)};
    elem->texture->nb_anim = (int)parser(buffer, "nb_anim", i);
    elem->texture->texture = sfTexture_createFromFile(
    (char *)parser(buffer, "img", i), NULL);
    MONS_SPRITE(elem) = sfSprite_create();
    elem->texture->texture_color = sfTexture_createFromFile(
    (char *)parser(buffer, "img_color", i), NULL);
    MONS_SPRITE_COLOR(elem) = sfSprite_create();
    sfSprite_setOrigin(MONS_SPRITE(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2, MONS_HEIGHT(elem)});
    sfSprite_setOrigin(MONS_SPRITE_COLOR(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2, MONS_HEIGHT(elem)});
}

void init_mons_stat(mons_t *elem, char *buffer, int i)
{
    elem->stat = malloc(sizeof(mons_stat_t));
    MONS_MAX_HP(elem) = (int)parser(buffer, "health", i);
    MONS_CURR_HP(elem) = MONS_MAX_HP(elem);
    MONS_HP(elem) = sfRectangleShape_create();
    sfRectangleShape_setOrigin(MONS_HP(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2+ 50, 0});
    sfRectangleShape_setSize(MONS_HP(elem), (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(MONS_HP(elem), sfGreen);
    MONS_SPEED(elem) = (int)parser(buffer, "speed", i);
    MONS_CURR_ATB(elem) = 0;
    elem->stat->atb = sfRectangleShape_create();
    sfRectangleShape_setOrigin(elem->stat->atb,
    (sfVector2f){MONS_WIDTH(elem) / 2 + 50, 0});
    sfRectangleShape_setSize(elem->stat->atb, (sfVector2f){0, 10});
    sfRectangleShape_setFillColor(elem->stat->atb, sfCyan);
}

void put_in_mons_list(game_t *game, mons_t **mons, char *buffer, int id)
{
    mons_t *elem = malloc(sizeof(mons_t));
    mons_t *last = *mons;
    int *skill_list = (int *)parser(buffer, "skill", id);
    char *skill_buffer = bread_file("ressources/json/ennemy_team.json", 20);

    init_mons_texture(elem, buffer, id);
    init_mons_stat(elem, buffer, id);
    elem->skill = NULL;
    for (int j = 0; j < (int)parser(buffer, "nb_skill", id); j++)
        put_in_skill_list(game, &elem->skill, skill_buffer, j + 1);
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
