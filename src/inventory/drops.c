/*
** EPITECH PROJECT, 2021
** droping funcs
** File description:
** drops
*/

#include "game.h"

void add_item_to_ground(list_t **dropped, raccoonmove_t *player, int id)
{
    item_t *loot = create_item(id);

    loot->is_in_inventory = false;
    loot->is_equiped = false;
    loot->index = 0;
    loot->pos.x = (player->raccoon_pos.x);
    loot->pos.y = (player->raccoon_pos.y += 10);
    sfSprite_setPosition(loot->sprite, loot->pos);
    list_stack(dropped, loot);
}