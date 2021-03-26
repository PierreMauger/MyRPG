/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_shader(game_t *game)
{
    game->shader = malloc(sizeof(shader_t));
    game->shader->skill = sfShader_createFromFile(NULL, NULL, SKILL_SHADER);
    game->shader->turn = sfShader_createFromFile(NULL, NULL, TURN_SHADER);
    game->shader->render = (sfRenderStates){
        .shader = game->shader->turn,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };
}
