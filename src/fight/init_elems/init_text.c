/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfText *init_text(game_t *game, char *string, sfColor color)
{
    sfText *text = sfText_create();

    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text, string);
    sfText_setColor(text, color);
    sfText_setOrigin(text,
    (sfVector2f){sfText_getGlobalBounds(text).width / 2, 0});
    return text;
}
