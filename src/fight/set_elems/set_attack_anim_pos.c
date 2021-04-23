/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void aoe_hit(game_t *game)
{
    for (mons_t *temp = game->ind->team; temp; temp = temp->next) {
        game->ind->target = temp;
        set_attack_anim(game);
    }
}

void set_attack_anim(game_t *game)
{
    game->set->in_anim = true;
    set_attack_anim_pos(game, game->ind->target);
}

void set_attack_anim_pos(game_t *game, mons_t *target)
{
    sfVector2f sprite_center = {sfSprite_getPosition(MONS_SPRITE(target)).x,
    sfSprite_getPosition(MONS_SPRITE(target)).y - 80};
    sfVector2f sprite_top = {sfSprite_getPosition(PTR_MONS_SPRITE).x,
    sfSprite_getPosition(PTR_MONS_SPRITE).y - PTR_MONS_RECT.height - 80};

    sfSprite_setOrigin(PTR_SKILL_ANIM_SPRITE,
    (sfVector2f){PTR_SKILL_ANIM_RECT.width / 2, 0});
    sfSprite_setPosition(PTR_SKILL_ANIM_SPRITE, sprite_center);
    sfText_setPosition(game->ind->damage, sprite_center);
    sfText_setPosition(game->ind->att_name, sprite_top);
}

void multi_hit(game_t *game, mons_t *target)
{
    if (target == NULL || game->ind->ptr_skill == NULL)
        return;
    if (CURR_ATT < game->ind->ptr_skill->stat->nb_hit - 1) {
        set_attack_anim_pos(game, game->ind->target);
        game->set->in_anim = true;
        CURR_ATT += 1;
    }
    target_team(game);
}
