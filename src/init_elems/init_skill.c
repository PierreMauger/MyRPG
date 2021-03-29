/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void put_in_skill_list(game_t *game, skill_t **skill, char *buffer, int id)
{
    skill_t *elem = malloc(sizeof(skill_t));
    skill_t *last = *skill;

    init_skill_stat(elem, buffer, id);
    init_skill_texture(elem, buffer, id);
    init_skill_anim(elem, buffer, id);
    init_skill_desc(game, elem, buffer, id);
    elem->next = NULL;
    if (*skill == NULL) {
        elem->next = *skill;
        *skill = elem;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = elem;
    }
}
