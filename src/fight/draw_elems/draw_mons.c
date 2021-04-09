/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_single_mons(game_t *game, mons_t *mons, sfRenderStates *shader)
{
    sfRenderTexture_drawSprite(GET_BUFFER, MONS_SPRITE(mons), shader);
    sfRenderTexture_drawSprite(GET_BUFFER, MONS_SPRITE_COLOR(mons), shader);
}

void draw_attack_shader(game_t *game)
{
    mons_t *temp;

    if (game->ind->ptr_skill->stat->target[CURR_ATT] == game->set->turn)
        temp = game->e_mons;
    else
        temp = game->p_mons;
    for (; temp; temp = temp->next) {
        if (game->set->in_anim)
            draw_single_mons(game, temp, &RENDER_TARGET);
    }
}

void draw_mons_sprites(game_t *game, mons_t *mons)
{
    if (mons == game->ind->ptr_mons)
        draw_single_mons(game, mons, &RENDER_TURN);
    else if (mons == game->ind->target)
        draw_single_mons(game, mons, &RENDER_TARGET);
    else
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
    if (game->ind->ptr_skill && game->ind->ptr_skill->stat->aoe[CURR_ATT])
        draw_attack_shader(game);
}
