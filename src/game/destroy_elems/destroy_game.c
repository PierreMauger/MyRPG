/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void destroy_map(game_t *game)
{
    sfTexture_destroy(game->move->my_texture);
    sfSprite_destroy(game->move->my_sprite);
    sfClock_destroy(game->move->map_clock);
    if (game->move->music.chest != NULL)
        sfMusic_destroy(game->move->music.chest);
    if (game->move->music.rain != NULL)
        sfMusic_destroy(game->move->music.rain);
    if (game->move->music.snow != NULL)
        sfMusic_destroy(game->move->music.snow);
    if (game->move->music.theme != NULL)
        sfMusic_destroy(game->move->music.theme);
    free_obs(game->move);
    free(game->text);
    free(game->move);
}

void destroy_game(game_t *game)
{
    destroy_quest(game->quest, game->qtext);
    destroy_fight(game);
    destroy_time(game->time);
    destroy_window(game->window);
    destroy_menu(game->menu);
    sfFont_destroy(game->font_fight);
    sfFont_destroy(game->font);
    destroy_map(game);
    free(game);
}
