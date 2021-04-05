/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "text.h"

int loop(sfRenderWindow *window, text_t *text, char *str)
{
    sfEvent event;
    sfTexture *my_texture = sfTexture_createFromFile("photo.png", NULL);
    sfSprite *my_sprite = sfSprite_create();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (0);
            }
            if (event.type == sfEvtMouseButtonPressed && text->clock == NULL)
                text->clock = sfClock_create();
        }
        sfRenderWindow_clear(window, sfWhite);
        sfSprite_setTexture(my_sprite, my_texture, sfTrue);
        sfRenderWindow_drawSprite(window, my_sprite, NULL);
        if (text->clock) text_defil(str, text, window);
        sfRenderWindow_display(window);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    text_t text = init_text(text);
    int err = 0;
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};
    window = sfRenderWindow_create(video_mode, "Text", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    err = loop(window, &text, av[1]);
    return (0);
}