/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfRenderStates init_renderstate(sfShader *shader)
{
    sfRenderStates render = (sfRenderStates){
        .shader = shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };
    return render;
}

void init_shader(game_t *game)
{
    game->shader = malloc(sizeof(shader_t));
    game->shader->skill = sfShader_createFromFile(NULL, NULL, SKILL_SHADER);
    game->shader->turn = sfShader_createFromFile(NULL, NULL, TURN_SHADER);
    game->shader->target = sfShader_createFromFile(NULL, NULL, TARGET_SHADER);
    game->shader->snow = sfShader_createFromFile(NULL, NULL, SNOW_SHADER);
    game->shader->rain = sfShader_createFromFile(NULL, NULL, RAIN_SHADER);
    RENDER_SKILL = init_renderstate(game->shader->skill);
    RENDER_TURN = init_renderstate(game->shader->turn);
    RENDER_TARGET = init_renderstate(game->shader->target);
    RENDER_SNOW = init_renderstate(game->shader->snow);
    RENDER_RAIN = init_renderstate(game->shader->rain);
}
