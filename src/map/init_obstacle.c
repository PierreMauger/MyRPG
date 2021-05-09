/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void init_struct_move_set(raccoonmove_t *move)
{
    move->speed = 3;
    move->item.boot = false;
    move->pnj.door_open = false;
    move->item.sword = false;
    move->item.door = false;
    move->pnj.speed_pnj = 2;
    move->obs.next_map = false;
    move->obs.back_map = false;
    move->obs.display_text_next = false;
    move->obs.display_text_back = false;
    move->chest.chest_open = false;
    move->chest.col_chest = false;
    move->pnj.exist = false;
    move->pnj.interaction = false;
    move->anim = false;
    move->chest.already_open_first = false;
    move->chest.already_open_second = false;
    move->key.col_key = false;
    move->item.key = false;
    move->climat_change = false;
}

static void init_struct_move_sprite(raccoonmove_t *move)
{
    sfIntRect first = {0, 0, 64, 128};

    init_music(move);
    move->pnj.idle = false;
    move->animrac.idle = true;
    move->my_texture = sfTexture_createFromFile(MAPMAISON, NULL);
    move->my_sprite = sfSprite_create();
    sfSprite_setTexture(move->my_sprite, move->my_texture, sfTrue);
    move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
    move->my_sprite_rac = sfSprite_create();
    sfSprite_setTexture(move->my_sprite_rac, move->my_texture_rac, sfTrue);
    move->key.my_texture = sfTexture_createFromFile(KEY, NULL);
    move->key.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->key.my_sprite, move->key.my_texture, sfTrue);
    move->fight_map_texture = sfTexture_createFromFile(FIGHT_MAP1, NULL);
    move->fight_map_sprite = sfSprite_create();
    sfSprite_setTexture(move->fight_map_sprite, move->fight_map_texture,
    sfTrue);
}

void init_struct_move(raccoonmove_t *move, sfRenderWindow *window)
{
    move->raccoon_pos.x = 555;
    move->raccoon_pos.y = 333;
    move->obs.fl_map_obstacle = MAP0;
    move->obs.index_obs = 0;
    move->window = window;
    move->map_clock = sfClock_create();
    move->animrac.anim_clock = sfClock_create();
    move->animrac.npc_clock = sfClock_create();
    move->animrac.enemy_clock = sfClock_create();
    move->enemy_info.nb_enemy = 2;
    move->animrac.anim_rac = 0;
    move->animrac.anim_npc = 0;
    move->animrac.anim_ene = 0;
    move->animrac.anim_npc_run = 0;
    move->animrac.speed_anim = 200000;
    init_struct_move_set(move);
    init_struct_move_sprite(move);
    init_enemy(move);
    if (init_obstacle(move) == 1)
        move->obs.index_obs = -1;
}
