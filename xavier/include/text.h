/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#ifndef TEXT_H
#define TEXT_H

#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"

typedef struct {
    sfClock *clock;
    char *save;
    size_t index;
    int size_font;
    int delay;
    sfVector2f pos;
    sfVector2f size_box;
} text_t;

text_t init_text(text_t text);
void text_defil(char *str, text_t *text, sfRenderWindow *window);

#endif