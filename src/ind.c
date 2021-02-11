/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void single_move_rect(sfIntRect *rect, int offset, int max_offset, int *booleen)
{
    rect->left += offset;
    if (rect->left >= max_offset) {
        rect->left = 0;
        *booleen = 0;
    }
}

void init_turn_ind(game_t *game)
{
    game->ind = malloc(sizeof(indicator_t));
    game->ind->texture = sfTexture_createFromFile(GRASS_IMG, NULL);
    game->ind->sprite = sfSprite_create();
    game->ind->rect = (sfIntRect){0, 0, 40, 80};
    game->ind->atexture = sfTexture_createFromFile(SLASH_IMG, NULL);
    game->ind->asprite = sfSprite_create();
    game->ind->arect = (sfIntRect){0, 0, 80, 80};
    game->ind->ptr_mons = NULL;
    game->ind->ptr_skill = NULL;
}

void draw_turn_ind(game_t *game)
{
    sfSprite_setOrigin(game->ind->sprite, sfSprite_getOrigin(game->ind->ptr_mons->sprite));
    sfSprite_setPosition(game->ind->sprite, (sfVector2f){sfSprite_getPosition(game->ind->ptr_mons->sprite).x + (game->ind->ptr_mons->width - 40) / 2, sfSprite_getPosition(game->ind->ptr_mons->sprite).y - 80});
    sfSprite_setTexture(game->ind->sprite, game->ind->texture, sfTrue);
    sfSprite_setTextureRect(game->ind->sprite, game->ind->rect);
    sfRenderWindow_drawSprite(game->window, game->ind->sprite, NULL);
}

void draw_single_attak_target(game_t *game)
{
    sfSprite_setTexture(game->ind->asprite, game->ind->atexture, sfTrue);
    sfSprite_setTextureRect(game->ind->asprite, game->ind->arect);
    sfRenderWindow_drawSprite(game->window, game->ind->asprite, NULL);
}

void draw_attak_target(game_t *game)
{
    mons_t *temp;

    if (game->in_anim == 1) {
        if (game->ind->ptr_skill->aoe == 1) {
            if (game->ind->ptr_skill->target == 1)
                temp = game->e_mons;
            else
                temp = game->p_mons;
            while (temp != NULL) {
                sfSprite_setOrigin(game->ind->asprite, (sfVector2f){temp->width / 2 + 40, 0});
                sfSprite_setPosition(game->ind->asprite, (sfVector2f){sfSprite_getPosition(temp->sprite).x + temp->width / 2, sfSprite_getPosition(temp->sprite).y - 80});
                draw_single_attak_target(game);
                temp = temp->next;
            }
        }
        else
            draw_single_attak_target(game);
    }
}

void destroy_turn_ind(indicator_t *ind)
{
    sfTexture_destroy(ind->texture);
    sfSprite_destroy(ind->sprite);
    free(ind);
}