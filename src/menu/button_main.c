/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include <game.h>
#include <button.h>

void draw_buttons(button_t **list)
{
    game_t *game;
    if (list == NULL || game == NULL)
        return;
    for (unsigned int itr = 0; list[itr]; ++itr) {
        sfWindow_drawSprite(GET_WINDOW, list[itr]->sprite, NULL);
    }
}

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

void set_btn_pos(button_t *btn, sfVector2f pos)
{
    if (!btn)
        return;
    btn->pos = pos;
    sfSprite_setPosition(btn->sprite, btn->pos);
}

void draw_button(game_t *game, button_t *btn)
{
    sfRenderWindow_drawSprite(GET_WINDOW, btn->sprite, NULL);
}

void set_button_rect(button_t *btn, sfIntRect rect)
{
    if (!btn)
        return;
    sfSprite_setTextureRect(btn->sprite, rect);
}

void set_button_color(button_t *btn, sfColor color)
{
    if (!btn)
        return;
    btn->color = color;
    sfSprite_setColor(btn->sprite, color);
}



