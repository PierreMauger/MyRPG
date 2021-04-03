/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_status_att(game_t *game, mons_t *mons, int *temp_x)
{
    if (mons->status->att_p) {
        sfSprite_setPosition(STATUS_SPRITE[att_p], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[att_p], NULL);
        *temp_x += 30;
    }
    if (mons->status->att_m) {
        sfSprite_setPosition(STATUS_SPRITE[att_m], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[att_m], NULL);
        *temp_x += 30;
    }
}

void draw_status_def(game_t *game, mons_t *mons, int *temp_x)
{
    if (mons->status->def_p) {
        sfSprite_setPosition(STATUS_SPRITE[def_p], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[def_p], NULL);
        *temp_x += 30;
    }
    if (mons->status->def_m) {
        sfSprite_setPosition(STATUS_SPRITE[def_m], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[def_m], NULL);
        *temp_x += 30;
    }
}

void draw_status_spe(game_t *game, mons_t *mons, int *temp_x)
{
    if (mons->status->spe_p) {
        sfSprite_setPosition(STATUS_SPRITE[spe_p], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[spe_p], NULL);
        *temp_x += 30;
    }
    if (mons->status->spe_m) {
        sfSprite_setPosition(STATUS_SPRITE[spe_m], (sfVector2f)
        {sfSprite_getPosition(mons->texture->sprite).x - 50 + *temp_x,
        sfSprite_getPosition(mons->texture->sprite).y + 50});
        sfRenderWindow_drawSprite(GET_WINDOW, STATUS_SPRITE[spe_m], NULL);
        *temp_x += 30;
    }
}

void draw_status(game_t *game, mons_t *mons)
{
    int temp_x = 0;

    draw_status_att(game, mons, &temp_x);
    draw_status_def(game, mons, &temp_x);
    draw_status_spe(game, mons, &temp_x);
}
