/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide_skill(game_t *game, skill_t *skill)
{
    sfVector2f skill_pos = sfSprite_getPosition(skill->sprite);

    if (game->mouse_pos.x > skill_pos.x && game->mouse_pos.x < skill_pos.x + 80 && game->mouse_pos.y > skill_pos.y && game->mouse_pos.y < skill_pos.y + 80)
        return 1;
    return 0;
}

void choose_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;

    while (temp != NULL) {
        if (check_collide_skill(game, temp) == 1)
            if (temp->passive == 0 && temp->act_cd == 0)
                game->ind->ptr_skill = temp;
        temp = temp->next;
    }
}
