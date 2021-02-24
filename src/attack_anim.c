/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void set_anim_pos(game_t *game, mons_t *target)
{
    sfSprite_setOrigin(game->ind->ptr_skill->asprite, (sfVector2f){target->width / 2 + 40, 0});
    sfSprite_setPosition(game->ind->ptr_skill->asprite, (sfVector2f){sfSprite_getPosition(target->sprite).x + target->width / 2, sfSprite_getPosition(target->sprite).y - 80});
}

void draw_single_attak_target(game_t *game)
{
    sfSprite_setTexture(game->ind->ptr_skill->asprite, game->ind->ptr_skill->atexture, sfTrue);
    sfSprite_setTextureRect(game->ind->ptr_skill->asprite, game->ind->ptr_skill->arect);
    sfRenderWindow_drawSprite(game->window, game->ind->ptr_skill->asprite, NULL);
}

void draw_attak_target(game_t *game)
{
    mons_t *temp;

    if (game->in_anim == 1) {
        if (game->ind->ptr_skill->aoe == 1) {
            if (game->ind->ptr_skill->target == game->turn)
                temp = game->e_mons;
            else
                temp = game->p_mons;
            while (temp != NULL) {
                set_anim_pos(game, temp);
                draw_single_attak_target(game);
                temp = temp->next;
            }
        }
        else
            draw_single_attak_target(game);
    }
}
