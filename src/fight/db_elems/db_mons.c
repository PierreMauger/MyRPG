/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_mons_status(mons_t *elem)
{
    elem->status = malloc(sizeof(mons_status_t));
    elem->status->att_p = 0;
    elem->status->att_m = 0;
    elem->status->def_p = 0;
    elem->status->def_m = 0;
    elem->status->spe_p = 0;
    elem->status->spe_m = 0;
}

void init_mons_texture(mons_t *elem, char *buffer, int id)
{
    char *img = (char *)parser(buffer, "img", id);

    elem->texture = malloc(sizeof(mons_texture_t));
    elem->texture->rect = (sfIntRect){0, 0, (int)parser(buffer, "width", id),
    (int)parser(buffer, "height", id)};
    elem->texture->nb_anim = (int)parser(buffer, "nb_anim", id);
    elem->texture->texture = sfTexture_createFromFile(img, NULL);
    MONS_SPRITE(elem) = sfSprite_create();
    sfSprite_setOrigin(MONS_SPRITE(elem),
    (sfVector2f){MONS_WIDTH(elem) / 2, MONS_HEIGHT(elem)});
    free(img);
}

void init_mons_stat(mons_t *elem, char *buffer, int id)
{
    elem->stat = malloc(sizeof(mons_stat_t));
    MONS_MAX_HP(elem) = (int)parser(buffer, "health", id);
    MONS_ATT(elem) = (float)parser(buffer, "att", id);
    MONS_DEF(elem) = (float)parser(buffer, "def", id);
    MONS_SPEED(elem) = (int)parser(buffer, "speed", id);
    MONS_XP(elem) = (int)parser(buffer, "xp", id);
    MONS_LEVEL(elem) = (int)parser(buffer, "level", id);
    MONS_CURR_HP(elem) = MONS_MAX_HP(elem);
    MONS_CURR_ATB(elem) = 0;
    MONS_HP(elem) = init_rectangle(BAR_SIZE, sfGreen, MONS_WIDTH(elem));
    MONS_ATB(elem) = init_rectangle(BAR_SIZE, sfCyan, MONS_WIDTH(elem));
}

void init_mons_skill(game_t *game, mons_t *elem, char *buffer, int id)
{
    int *skill_list = (int *)parser(buffer, "skill", id);
    char *skill_buffer = bread_file(JSON_SKILL, 20);

    elem->skill = NULL;
    for (int j = 0; j < (int)parser(buffer, "nb_skill", id); j++)
        put_in_skill_list(game, &elem->skill, skill_buffer, skill_list[j]);
    free(skill_list);
    free(skill_buffer);
}

void put_in_mons_list(game_t *game, mons_t **mons, char *buffer, int id)
{
    mons_t *elem = malloc(sizeof(mons_t));
    mons_t *last = *mons;

    init_mons_status(elem);
    init_mons_texture(elem, buffer, id);
    init_mons_stat(elem, buffer, id);
    init_mons_skill(game, elem, buffer, id);
    elem->id = id;
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
