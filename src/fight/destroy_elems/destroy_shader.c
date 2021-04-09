/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_shader(shader_t *shader)
{
    sfShader_destroy(shader->skill);
    sfShader_destroy(shader->turn);
    sfShader_destroy(shader->target);
    sfShader_destroy(shader->snow);
    free(shader);
}
