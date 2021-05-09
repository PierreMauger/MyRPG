/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

sfText *init_font(sfText *txt, sfVector2f pos, char *font, char *text)
{
    txt = sfText_create();
    sfFont *menu = sfFont_createFromFile(font);

    if (!menu)
        return (NULL);
    sfText_setPosition(txt, pos);
    sfText_setString(txt, text);
    sfText_setFont(txt, menu);
    return (txt);
}

void set_size_font(sfText *txt, unsigned int size)
{
    sfText_setCharacterSize(txt, size);
}

void set_color(sfText *txt, sfColor color)
{
    sfText_setColor(txt, color);
}

void show_font(game_t *game, sfText *txt)
{
    sfRenderWindow_drawText(GET_WINDOW, txt, NULL);
}
