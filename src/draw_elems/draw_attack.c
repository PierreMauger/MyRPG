/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static int last_anim_frame(sfIntRect rect, int nb_anim)
{
    if (rect.left == rect.width * (nb_anim - 1))
        return 1;
    return 0;
}

void draw_single_attak_target(game_t *game)
{
    sfSprite_setTexture(PTR_SKILL_ANIM_SPRITE, PTR_SKILL_ANIM_TEX, sfTrue);
    sfSprite_setTextureRect(PTR_SKILL_ANIM_SPRITE, PTR_SKILL_ANIM_RECT);
    sfRenderWindow_drawSprite(GET_WINDOW, PTR_SKILL_ANIM_SPRITE, NULL);
    sfText_setString(game->ind->damage,
    bitoa(game->ind->ptr_skill->stat->coef[CURR_ATT]));
    sfText_setOrigin(game->ind->damage, (sfVector2f)
    {sfText_getGlobalBounds(game->ind->damage).width / 2, 0});
    sfText_setString(game->ind->att_name, game->ind->ptr_skill->stat->name);
    sfText_setOrigin(game->ind->att_name, (sfVector2f)
    {sfText_getGlobalBounds(game->ind->att_name).width / 2, 0});
    sfRenderWindow_drawText(GET_WINDOW, game->ind->att_name, NULL);
    if (game->ind->ptr_skill->stat->coef[CURR_ATT] != 0 &&
    last_anim_frame(PTR_SKILL_ANIM_RECT, PTR_SKILL_ANIM_NB))
        sfRenderWindow_drawText(GET_WINDOW, game->ind->damage, NULL);
}

void draw_attack_aoe(game_t *game)
{
    mons_t *temp;

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

void draw_attak_target(game_t *game)
{
    if (game->set->in_anim == true) {
        if (game->ind->ptr_skill->stat->aoe[CURR_ATT] == true) {
            draw_attack_aoe(game);
        }
        else {
            set_attack_anim_pos(game, game->ind->target);
            draw_single_attak_target(game);
        }
    }
}
