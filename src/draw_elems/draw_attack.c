/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_single_attak_target(game_t *game)
{
    sfSprite_setTexture(game->ind->ptr_skill->anim->asprite, game->ind->ptr_skill->anim->atexture, sfTrue);
    sfSprite_setTextureRect(game->ind->ptr_skill->anim->asprite, game->ind->ptr_skill->anim->arect);
    sfRenderWindow_drawSprite(game->window->window, game->ind->ptr_skill->anim->asprite, NULL);
    sfText_setString(game->ind->damage, nbr_to_str(game->ind->ptr_skill->stat->coef[CURR_ATT]));
    sfText_setOrigin(game->ind->damage, (sfVector2f){sfText_getGlobalBounds(game->ind->damage).width / 2, 0});
    if (game->ind->ptr_skill->stat->coef[CURR_ATT] != 0 && game->ind->ptr_skill->anim->arect.left == game->ind->ptr_skill->anim->arect.width * (game->ind->ptr_skill->stat->anim_nb - 1))
        sfRenderWindow_drawText(game->window->window, game->ind->damage, NULL);
}

void draw_attak_target(game_t *game)
{
    mons_t *temp;

    if (game->set->in_anim == true) {
        if (game->ind->ptr_skill->stat->aoe[CURR_ATT] == true) {
            if (game->ind->ptr_skill->stat->target[CURR_ATT] == game->set->turn)
                temp = game->e_mons;
            else
                temp = game->p_mons;
            while (temp != NULL) {
                set_attack_anim_pos(game, temp);
                draw_single_attak_target(game);
                temp = temp->next;
            }
        }
        else {
            set_attack_anim_pos(game, game->ind->target);
            draw_single_attak_target(game);
        }
    }
}
