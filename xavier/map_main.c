/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void display_everything(sfRenderWindow *window, dinomove_t *move)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, move->my_sprite, NULL);
    my_perso(window, move);
    if (move->obs.display_text_next == true)
        display_next_map(move);
    if (move->obs.display_text_back == true)
        display_back_map(move);
    sfRenderWindow_display(window);
}

static int map_event(dinomove_t *move, sfEvent event, int *passed)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyK)
            && move->obs.display_text_next == true)
            move->obs.next_map = true;
        if (sfKeyboard_isKeyPressed(sfKeyK)
            && move->obs.display_text_back == true)
            move->obs.back_map = true;
        create_col(move->dino_pos.x, move->dino_pos.y, move, passed);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(move->window);
}

static void check_change_map(dinomove_t *move)
{
    if (move->obs.next_map == true)
        change_map_next(move);
    if (move->obs.back_map == true)
        change_map_back(move);
}

static int loop(sfRenderWindow *window)
{
    sfEvent event;
    sfVector2f size = {0.75, 0.75};
    dinomove_t move = init_struct_move(move, window);
    int passed = 0;

    if (move.obs.index_obs == -1)
        return (-1);
    sfSprite_setTexture(move.my_sprite, move.my_texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            map_event(&move, event, &passed);
        check_change_map(&move);
        ch_move(window, &move);
        display_everything(window, &move);
        int a = move.dino_pos.x;
        int b = move.dino_pos.y;
        printf("%d %d\n", a, b);
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