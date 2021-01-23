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

void put_in_mons_list(p_mons_t **mons, sfVector2f pos)
{
    p_mons_t *element = malloc(sizeof(p_mons_t));

    element->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *mons;
    *mons = element;
}

void init_mons(game_t *game)
{
    sfVector2f pos = {200, 400};

    for (int i = 0; i < 3; i++) {
        put_in_mons_list(&game->mons, pos);
        pos.x += 200;
    }
}

void draw_mons(game_t *game)
{
    p_mons_t *temp = game->mons;

    while (temp != NULL) {
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
    }
}

void anim_mons(game_t *game)
{
    p_mons_t *temp = game->mons;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        while (temp != NULL) {
            move_rect(&temp->rect, 40, 80);
            temp = temp->next;
        }
        sfClock_restart(game->clock);
    }
}

void destroy_mons(p_mons_t *mons)
{
    while (mons != NULL) {
        sfTexture_destroy(mons->texture);
        sfSprite_destroy(mons->sprite);
        mons = mons->next;
    }
}