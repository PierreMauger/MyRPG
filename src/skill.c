/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide_skill(skill_t *skill, sfVector2f mouse_pos)
{
    sfVector2f skill_pos = sfSprite_getPosition(skill->sprite);

    if (mouse_pos.x > skill_pos.x && mouse_pos.x < skill_pos.x + 80 && mouse_pos.y > skill_pos.y && mouse_pos.y < skill_pos.y + 80)
        return 1;
    return 0;
}

void choose_skill(game_t *game, sfVector2i mouse_pos)
{
    skill_t *temp = game->ind->temp;

    while (temp != NULL) {
        if (check_collide_skill(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
            game->ind->temp = temp;
        temp = temp->next;
    }
}

void draw_skill(game_t *game)
{
    skill_t *temp = game->ind->ptr->skill;
    int x = 1600;

    while (temp != NULL) {
        sfSprite_setPosition(temp->sprite, (sfVector2f){x, 900});
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
        x += 100;
    }
}