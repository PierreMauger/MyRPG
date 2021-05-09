/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_mons_pos(mons_t *mons, sfVector2f pos, float size)
{
    sfSprite_setPosition(MONS_SPRITE(mons), pos);
    sfRectangleShape_setPosition(MONS_HP(mons),
    (sfVector2f){pos.x + MONS_WIDTH(mons) / 2, pos.y + 10});
    sfRectangleShape_setPosition(mons->stat->atb,
    (sfVector2f){pos.x + MONS_WIDTH(mons) / 2, pos.y + 30});
    sfSprite_setScale(MONS_SPRITE(mons), (sfVector2f){size, size});
}

void init_all_pos(game_t *game)
{
    sfVector2f p_pos = {400, 800};
    sfVector2f e_pos = {1400, 800};
    float p_size = 1.3;
    float e_size = 1.3;

    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        init_mons_pos(temp, p_pos, p_size);
        p_pos = (sfVector2f){p_pos.x + 50, p_pos.y - 175};
        p_size -= 0.3;
    }
    for (mons_t *temp = game->e_mons; temp; temp = temp->next) {
        init_mons_pos(temp, e_pos, e_size);
        e_pos = (sfVector2f){e_pos.x - 50, e_pos.y - 175};
        e_size -= 0.3;
    }
}

void init_mons(game_t *game)
{
    char *buffer = bread_file(JSON_MONS, 20);

    if (!buffer || bstrlen(buffer) < 10)
        return;
    game->p_mons = NULL;
    for (int i = 1; i < 2; i++)
        put_in_mons_list(game, &game->p_mons, buffer, i);
    free(buffer);
}
