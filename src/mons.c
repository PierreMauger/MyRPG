/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void move_rect(sfIntRect *rect, int offset, int max_offset)
{
    rect->left += offset;
    if (rect->left >= max_offset)
        rect->left = 0;
}

void init_mons(game_t *game)
{
    game->mons = malloc(sizeof(mons_t));
    game->mons->rect = (sfIntRect){0, 0, 40, 80};
    game->mons->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    game->mons->sprite = sfSprite_create();
    sfSprite_setPosition(game->mons->sprite, (sfVector2f){200, 400});
}

void draw_mons(game_t *game)
{
    sfSprite_setTexture(game->mons->sprite, game->mons->texture, sfTrue);
    sfSprite_setTextureRect(game->mons->sprite, game->mons->rect);
    sfRenderWindow_drawSprite(game->window, game->mons->sprite, NULL);
}

float anim_player(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        move_rect(&game->mons->rect, 40, 80);
        sfClock_restart(game->clock);
    }
    return game->seconds;
}

void destroy_mons(mons_t *mons)
{
    sfTexture_destroy(mons->texture);
    sfSprite_destroy(mons->sprite);
    free(mons);
}