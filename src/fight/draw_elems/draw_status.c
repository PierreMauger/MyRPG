/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_status_att(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos)
{
    if (mons->status->att_p) {
        sfSprite_setPosition(STATUS_SPRITE[att_p], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[att_p], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->att_p));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
    if (mons->status->att_m) {
        sfSprite_setPosition(STATUS_SPRITE[att_m], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[att_m], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->att_m));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
}

void draw_status_def(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos)
{
    if (mons->status->def_p) {
        sfSprite_setPosition(STATUS_SPRITE[def_p], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[def_p], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->def_p));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
    if (mons->status->def_m) {
        sfSprite_setPosition(STATUS_SPRITE[def_m], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[def_m], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->def_m));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
}

void draw_status_spe(game_t *game, mons_t *mons, int *temp_x, sfVector2f pos)
{
    if (mons->status->spe_p) {
        sfSprite_setPosition(STATUS_SPRITE[spe_p], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[spe_p], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->spe_p));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
    if (mons->status->spe_m) {
        sfSprite_setPosition(STATUS_SPRITE[spe_m], (sfVector2f){pos.x - 50 +
        *temp_x, pos.y + 50});
        sfRenderTexture_drawSprite(GET_BUFFER, STATUS_SPRITE[spe_m], NULL);
        sfText_setPosition(game->status->text, (sfVector2f){pos.x - 35 +
        *temp_x, pos.y + 75});
        sfText_setString(game->status->text, bitoa(mons->status->spe_m));
        sfRenderTexture_drawText(GET_BUFFER, game->status->text, NULL);
        *temp_x += 30;
    }
}

void draw_status(game_t *game, mons_t *mons)
{
    int temp_x = 0;

    draw_status_att(game, mons, &temp_x,
    sfSprite_getPosition(mons->texture->sprite));
    draw_status_def(game, mons, &temp_x,
    sfSprite_getPosition(mons->texture->sprite));
    draw_status_spe(game, mons, &temp_x,
    sfSprite_getPosition(mons->texture->sprite));
}
