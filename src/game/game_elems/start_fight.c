/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void reset_fight(game_t *game)
{
    for (mons_t *temp = game->p_mons; temp; temp = temp->next) {
        MONS_CURR_ATB(temp) = 0;
        cooldown_refresh(temp);
        temp->status->att_p = 0;
        temp->status->att_m = 0;
        temp->status->def_p = 0;
        temp->status->def_m = 0;
        temp->status->spe_p = 0;
        temp->status->spe_m = 0;
    }
}

void start_fight(game_t *game)
{
    char *buffer = bread_file(JSON_MONS, 20);

    if (!buffer || bstrlen(buffer) < 10)
        return;
    music_dest(game->move, 1);
    game->e_mons = NULL;
    for (int i = 1; i < game->move->enemy_info.nb_enemy; i++) {
        if (game->move->enemy_info.nb_enemy == 4)
            put_in_mons_list(game, &game->e_mons, buffer, i + 1);
        else
            put_in_mons_list(game, &game->e_mons, buffer, 4);
    }
    init_all_pos(game);
    reset_fight(game);
    free(buffer);
    sfRenderTexture_display(GET_BUFFER);
}
