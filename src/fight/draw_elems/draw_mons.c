/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static int is_ennemy(game_t *game, mons_t *mons)
{
    for (mons_t *temp = game->e_mons; temp; temp = temp->next)
        if (temp == mons)
            return 1;
    return 0;
}

void draw_single_mons(game_t *game, mons_t *mons, sfRenderStates *shader)
{
    sfRenderTexture_drawSprite(GET_BUFFER, MONS_SPRITE(mons), shader);
}

void draw_mons_sprites(game_t *game, mons_t *mons)
{
    if (mons == game->ind->ptr_mons) {
        draw_single_mons(game, mons, &RENDER_TURN);
        return;
    }
    if (mons == game->ind->target &&
    !game->ind->ptr_skill->stat->target[CURR_ATT]) {
        draw_single_mons(game, mons, &RENDER_TARGET);
        return;
    }
    if (game->ind->ptr_skill && game->ind->ptr_skill->stat->aoe[CURR_ATT]
    && game->set->in_anim && game->ind->ptr_skill->stat->target[CURR_ATT] !=
    is_ennemy(game, mons)) {
        draw_single_mons(game, mons, &RENDER_TARGET);
        return;
    }
    draw_single_mons(game, mons, NULL);
}

void draw_mons(game_t *game, mons_t *head)
{
    for (mons_t *temp = head; temp; temp = temp->next) {
        set_texture_mons(temp);
        draw_mons_sprites(game, temp);
        draw_status(game, temp);
        sfRenderTexture_drawRectangleShape(GET_BUFFER, MONS_HP(temp), NULL);
        sfRenderTexture_drawRectangleShape(GET_BUFFER, temp->stat->atb, NULL);
    }
}
