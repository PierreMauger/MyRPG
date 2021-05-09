/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void change_anim_idle(raccoonmove_t *move)
{
    sfIntRect first = {0, 0, 64, 128};

    if (sfClock_getElapsedTime(move->animrac.anim_clock).microseconds < 450000)
        return;
    sfTexture_destroy(move->my_texture_rac);
    if (move->animrac.anim_rac == 0 || move->animrac.anim_rac == 1) {
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 2;
    }
    else {
        first.left += 128;
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 0;
    }
    sfClock_restart(move->animrac.anim_clock);
}

static void change_anim(raccoonmove_t *move, sfIntRect first)
{
    if (move->animrac.idle == true) {
        change_anim_idle(move);
        return;
    }
    sfTexture_destroy(move->my_texture_rac);
    if (move->animrac.anim_rac == 0) {
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 1;
    }
    else if (move->animrac.anim_rac == 1) {
        first.left += 128;
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 2;
    }
    else {
        first.left += 64;
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 0;
    }
    sfClock_restart(move->animrac.anim_clock);
}

void my_perso(sfRenderWindow *window, raccoonmove_t *move)
{
    sfIntRect first = {0, 0, 64, 128};

    if (move->anim == true) {
        sfTexture_destroy(move->my_texture_rac);
        move->my_texture_rac = sfTexture_createFromFile(RACCOON, &first);
        move->animrac.anim_rac = 0;
    }
    else if (sfClock_getElapsedTime(move->animrac.anim_clock)
        .microseconds >= move->animrac.speed_anim) {
        change_anim(move, first);
    }
    sfSprite_setTexture(move->my_sprite_rac, move->my_texture_rac, sfTrue);
    sfSprite_setPosition(move->my_sprite_rac, move->raccoon_pos);
    sfRenderWindow_drawSprite(window, move->my_sprite_rac, NULL);
}

int check_use_now(raccoonmove_t *move)
{
    if (move->anim == true)
        return (0);
    if (move->obs.display_text_next == true
        || move->obs.display_text_back == true)
        return (1);
    if (check_pnj_col(move) == 1)
        return (2);
    if (move->chest.col_chest == true
        && ((move->chest.already_open_first == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP0) == 0)
        || (move->chest.already_open_second == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0)))
        return (3);
    if (move->key.col_key == true && move->item.key == false)
        return (4);
    return (0);
}

void display_use(raccoonmove_t *move)
{
    sfTexture *back = sfTexture_createFromFile(
        "ressources/sprites/keyboard_key_e.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f pos = {1780, 10};

    sfSprite_setPosition(my_spr, pos);
    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(move->window, my_spr, NULL);
    sfTexture_destroy(back);
    sfSprite_destroy(my_spr);
}
