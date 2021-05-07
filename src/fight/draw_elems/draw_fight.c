/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void change_background(game_t *game)
{
    if ((bstrcmp(game->move->obs.fl_map_obstacle, MAP1) == 0))
        game->move->fight_map_texture = sfTexture_createFromFile(FIGHT_MAP1,
        NULL);
    if ((bstrcmp(game->move->obs.fl_map_obstacle, MAP2) == 0))
        game->move->fight_map_texture = sfTexture_createFromFile(FIGHT_MAP2,
        NULL);
    sfSprite_setTexture(game->move->fight_map_sprite,
    game->move->fight_map_texture, sfTrue);
}

void draw_fight(game_t *game)
{
    sfRenderWindow_clear(GET_WINDOW, sfBlack);
    sfRenderTexture_clear(GET_BUFFER, sfBlack);
    sfRenderTexture_drawSprite(GET_BUFFER, game->move->fight_map_sprite, NULL);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    if (game->set->in_anim == false && game->set->attack == true) {
        draw_turn_ind(game);
        draw_skill(game);
    }
    draw_attak_target(game);
    game->window->tex = (sfTexture *)sfRenderTexture_getTexture(GET_BUFFER);
    sfSprite_setTexture(game->window->sprite, game->window->tex, sfFalse);
    sfRenderWindow_drawSprite(GET_WINDOW, game->window->sprite, NULL);
    sfRenderTexture_display(GET_BUFFER);
    sfRenderWindow_display(GET_WINDOW);
}
