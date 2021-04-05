/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfText *init_text(game_t *game, char *str, sfColor color)
{
    sfText *text = sfText_create();

    sfText_setFont(text, game->font_fight);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    sfText_setOrigin(text,
    (sfVector2f){sfText_getGlobalBounds(text).width / 2, 0});
    free(str);
    return text;
}
