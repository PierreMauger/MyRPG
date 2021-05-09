/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include <game.h>
#include <button.h>

void draw_buttons(game_t *game, button_t **list)
{
    if (list == NULL || game == NULL)
        return;
    for (unsigned int itr = 0; list[itr]; ++itr) {
        sfRenderWindow_drawSprite(GET_WINDOW, list[itr]->sprite, NULL);
    }
}

button_t **list_button(int size_nbr)
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
    sfFloatRect rect = sfSprite_getGlobalBounds(btn->sprite);

    if (!game || !btn)
        return (false);
    if (game->mouse_pos.x > rect.left && game->mouse_pos.x < rect.left +
    rect.width && game->mouse_pos.y > rect.top && game->mouse_pos.y <
    rect.top + rect.height)
        return (true);
    return (false);
}
