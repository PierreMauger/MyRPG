/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_single_attak_target(game_t *game)
{
    sfSprite_setTexture(game->ind->ptr_skill->asprite, game->ind->ptr_skill->atexture, sfTrue);
    sfSprite_setTextureRect(game->ind->ptr_skill->asprite, game->ind->ptr_skill->arect);
    sfRenderWindow_drawSprite(game->window, game->ind->ptr_skill->asprite, NULL);
    sfText_setString(game->ind->damage, nbr_to_str(game->ind->ptr_skill->coef[CURR_ATT]));
    sfText_setOrigin(game->ind->damage, (sfVector2f){sfText_getGlobalBounds(game->ind->damage).width / 2, 0});
    if (game->ind->ptr_skill->coef[CURR_ATT] != 0 && game->ind->ptr_skill->arect.left == game->ind->ptr_skill->arect.width * (game->ind->ptr_skill->anim_nb - 1))
        sfRenderWindow_drawText(game->window, game->ind->damage, NULL);
}

void draw_attak_target(game_t *game)
{
    mons_t *temp;

    if (game->in_anim == true) {
        if (game->ind->ptr_skill->aoe[CURR_ATT] == true) {
            if (game->ind->ptr_skill->target[CURR_ATT] == game->turn)
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
