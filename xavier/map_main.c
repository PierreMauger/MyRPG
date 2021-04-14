/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

int ch_move(sfRenderWindow *window, dinomove_t *move)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (move->dino_pos.x >= 0 && check_obs(move, 0) == 0)
            move->dino_pos.x -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (move->dino_pos.x <= 1850 && check_obs(move, 1) == 0)
            move->dino_pos.x += 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (move->dino_pos.y >= 0 && check_obs(move, 2) == 0)
            move->dino_pos.y -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (move->dino_pos.y <= 950 && check_obs(move, 3) == 0)
            move->dino_pos.y += 1.5;
    }
}

int my_perso(sfRenderWindow *window, dinomove_t *move)
{
    sfTexture *back = sfTexture_createFromFile("dino.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f sprite_size = {0.6, 0.6};
    sfSprite_setPosition(my_spr, move->dino_pos);
    sfSprite_scale(my_spr, sprite_size);

    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

int loop(sfRenderWindow *window)
{
    sfEvent event;
    sfVector2f size = {0.75, 0.75};
    dinomove_t move = init_struct_move(move);

    if (move.index_obs == -1) return (-1);
    move.my_texture = sfTexture_createFromFile("map/maison.jpg", NULL);
    move.my_sprite = sfSprite_create(), move.window = window;
    sfSprite_setTexture(move.my_sprite, move.my_texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        ch_move(window, &move), sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, move.my_sprite, NULL);
        my_perso(window, &move), sfRenderWindow_display(window);
    }
    return (0);
}

int main(int ac, char **av)
{
    int err = 0;
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080};
    window = sfRenderWindow_create(video_mode, "map", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 90);
    err = loop(window);
    return (0);
}