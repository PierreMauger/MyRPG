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

void put_in_p_mons_list(p_mons_t **p_mons, sfVector2f pos)
{
    p_mons_t *element = malloc(sizeof(p_mons_t));

    element->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *p_mons;
    *p_mons = element;
}

void put_in_e_mons_list(e_mons_t **e_mons, sfVector2f pos)
{
    e_mons_t *element = malloc(sizeof(e_mons_t));

    element->texture = sfTexture_createFromFile(DIRT_IMG, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, pos);
    element->rect = (sfIntRect){0, 0, 40, 80};
    element->next = *e_mons;
    *e_mons = element;
}

void init_mons(game_t *game)
{
    sfVector2f p_pos = {200, 800};
    sfVector2f e_pos = {600, 400};

    for (int i = 0; i < 3; i++) {
        put_in_p_mons_list(&game->p_mons, p_pos);
        put_in_e_mons_list(&game->e_mons, e_pos);
        p_pos.x += 200;
        e_pos.x += 200;
    }
}

void draw_mons(game_t *game)
{
    p_mons_t *temp = game->p_mons;
    e_mons_t *temp2 = game->e_mons;

    while (temp != NULL) {
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
    }
    while (temp2 != NULL) {
        sfSprite_setTexture(temp2->sprite, temp2->texture, sfTrue);
        sfSprite_setTextureRect(temp2->sprite, temp2->rect);
        sfRenderWindow_drawSprite(game->window, temp2->sprite, NULL);
        temp2 = temp2->next;
    }
}

void anim_mons(game_t *game)
{
    p_mons_t *temp = game->p_mons;
    e_mons_t *temp2 = game->e_mons;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        while (temp != NULL) {
            move_rect(&temp->rect, 40, 80);
            temp = temp->next;
        }
        while (temp2 != NULL) {
            move_rect(&temp2->rect, 40, 80);
            temp2 = temp2->next;
        }
        sfClock_restart(game->clock);
    }
}

void destroy_mons(p_mons_t *p_mons, e_mons_t *e_mons)
{
    while (p_mons != NULL) {
        sfTexture_destroy(p_mons->texture);
        sfSprite_destroy(p_mons->sprite);
        p_mons = p_mons->next;
    }
    while (e_mons != NULL) {
        sfTexture_destroy(e_mons->texture);
        sfSprite_destroy(e_mons->sprite);
        e_mons = e_mons->next;
    }
}