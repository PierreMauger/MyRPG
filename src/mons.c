/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_mons(game_t *game)
{
    sfVector2f p_pos = {200, 800};
    sfVector2f e_pos = {600, 400};
    char p_team[3] = "ddd";
    char e_team[3] = "abc";

    for (int i = 0; i < 3; i++) {
        put_in_mons_list(&game->p_mons, p_pos, p_team[i]);
        put_in_mons_list(&game->e_mons, e_pos, e_team[i]);
        p_pos.x += 200;
        e_pos.x += 350;
    }
}

void draw_mons(game_t *game, mons_t *mons)
{
    mons_t *temp = mons;

    while (temp != NULL) {
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        sfSprite_setTexture(temp->sprite_color, temp->texture_color, sfTrue);
        sfSprite_setTextureRect(temp->sprite_color, temp->rect);
        sfRenderWindow_drawSprite(game->window, temp->sprite_color, NULL);
        sfRenderWindow_drawRectangleShape(game->window, temp->hp, NULL);
        sfRenderWindow_drawRectangleShape(game->window, temp->atb, NULL);
        temp = temp->next;
    }
}

void attack_activation(game_t *game)
{
    mons_t *temp = game->ind->team;

    if (game->ind->ptr_skill->aoe == 1)
        while (temp != NULL) {
            game->ind->target = temp;
            attack_hit(game, game->ind->team, game->ind->target);
            temp = temp->next;
        }
    else
        attack_hit(game, game->ind->team, game->ind->target);
}

void anim_mons(game_t *game)
{
    mons_t *temp = game->p_mons;
    mons_t *temp2 = game->e_mons;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > ANIME_TIME) {
        while (temp != NULL) {
            move_rect(&temp->rect, temp->width, temp->width * temp->nb_anim);
            temp = temp->next;
        }
        while (temp2 != NULL) {
            move_rect(&temp2->rect, temp2->width, temp2->width * temp2->nb_anim);
            temp2 = temp2->next;
        }
        move_rect(&game->ind->rect, 40, 80);
        if (game->in_anim == 1) {
            single_move_rect(&game->ind->arect, 80, 320, &game->in_anim);
            if (game->in_anim == 0)
                test(game);
        }
        sfClock_restart(game->clock);
    }
}

void destroy_mons(mons_t *mons)
{
    while (mons != NULL) {
        sfTexture_destroy(mons->texture);
        sfSprite_destroy(mons->sprite);
        mons = mons->next;
    }
}
