/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

button_t **list_button(game_t *game, int size_nbr)
{
    button_t **btn_list = malloc(sizeof(button_t) * size_nbr);

    if (btn_list == NULL)
        return (NULL);
    for (int i = 0; i <= size_nbr; ++i) {
        btn_list[i] = NULL;
    }
    return (btn_list);
}

button_t *create_button(sfVector2f pos, char *path, sfIntRect rect)
{
    button_t *btn = malloc(sizeof(button_t));
    
    if (!btn)
        return (NULL);
    btn->pos = pos;
    btn->rect = rect;
    btn->sprite = sfSprite_create();
    btn->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setPosition(btn->sprite, btn->pos);
    sfSprite_setTexture(btn->sprite, btn->texture, sfTrue);
    sfSprite_setTextureRect(btn->sprite, btn->rect);
    return (btn);
}

bool is_mouse_on_button(game_t *game, button_t *btn)
{
    sfVector2i mouse;
    sfVector2f tleft;
    sfVector2f tright;

    if (!game || !btn)
        return (false);
    mouse = sfMouse_getPosition(GET_WINDOW);
    tleft = btn->pos;
    tright.x = btn->pos.x + btn->rect.width;
    tright.y = btn->pos.y + btn->rect.height;
    if (mouse.x < tleft.x || mouse.y < tleft.y)
        return (false);
    return (mouse.x < tright.x && mouse.y < tright.y);
}