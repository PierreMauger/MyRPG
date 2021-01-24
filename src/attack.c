/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int check_collide(mons_t *mons, sfVector2f mouse_pos)
{
    sfVector2f mons_pos = sfSprite_getPosition(mons->sprite);
    mons_pos.x -= mons->width / 2;
    mons_pos.y -= mons->height;

    if (mouse_pos.x > mons_pos.x && mouse_pos.x < mons_pos.x + mons->width && mouse_pos.y > mons_pos.y && mouse_pos.y < mons_pos.y + mons->height)
        return 1;
    return 0;
}

void attack_hit(game_t *game, mons_t *mons)
{
    mons->curr_hp -= 30;
    if (mons->curr_hp < 0)
        mons->curr_hp = 0;
    sfRectangleShape_setSize(mons->hp, (sfVector2f){((float)mons->curr_hp / (float)mons->max_hp) * 100, 10});
    atb_reset(game);
    game->attack = 0;
}
void attack(game_t *game, sfVector2i mouse_pos)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    if (game->turn == 0) {
        while (temp2 != NULL) {
            if (check_collide(temp2, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
                attack_hit(game, temp2);
            temp2 = temp2->next;
        }
    }
    else {
        while (temp != NULL) {
            if (check_collide(temp, (sfVector2f){mouse_pos.x, mouse_pos.y}) == 1)
                attack_hit(game, temp);
            temp = temp->next;
        }
    }
}