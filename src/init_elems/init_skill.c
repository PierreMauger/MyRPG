/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void put_in_skill_list(skill_t **skill, game_t *game, char name)
{
    skill_t *elem = malloc(sizeof(skill_t));
    skill_t *last = *skill;
    int i = find_in_skill_database(name);

    init_skill_stat(elem, i);
    init_skill_texture(elem, i);
    init_skill_anim(elem, i);
    init_skill_desc(elem, game, i);
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
