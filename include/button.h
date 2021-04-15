/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "blib.h"
#include <stdbool.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct button_s {
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfColor color;
}button_t;

#endif
