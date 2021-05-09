/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"
#include "game.h"

void display_mykey(raccoonmove_t *move, int x, int y)
{
    sfVector2f pos_key = {1792 + x, 917 + y};

    if (move->item.key == false
        && bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0) {
        sfSprite_setPosition(move->key.my_sprite, pos_key);
        sfRenderWindow_drawSprite(move->window, move->key.my_sprite, NULL);
    }
}

static void displ_map(sfRenderWindow *window, game_t *game)
{
    if (bstrcmp(game->move->obs.fl_map_obstacle, MAP1) == 0)
        sfRenderWindow_drawSprite(window, game->move->my_sprite, &RENDER_RAIN);
    else if (bstrcmp(game->move->obs.fl_map_obstacle, MAP2) == 0)
        sfRenderWindow_drawSprite(window, game->move->my_sprite, &RENDER_SNOW);
    else
        sfRenderWindow_drawSprite(window, game->move->my_sprite, NULL);
}

void displ_all(sfRenderWindow *window, raccoonmove_t *move, text_t *text,
game_t *game)
{
    sfRenderWindow_clear(window, sfWhite);
    displ_map(window, game);
    anim_all(game);
    if (move->pnj.exist == true
        && bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0)
        display_pnj(move);
    display_mykey(move, 0, 0);
    my_perso(window, move);
    check_if_combat(move);
    if (check_use_now(move) >= 1)
        display_use(move);
    if (text->clock)
        text_defil(move->sentence[text->str_index], text, window);
    if (move->chest.chest_open == true)
        chest_open(move);
}

void check_change_map(raccoonmove_t *move, text_t *text, game_t *game)
{
    if (move->obs.next_map == true)
        change_map_next(move, text, game);
    if (move->obs.back_map == true)
        change_map_back(move, game);
}
