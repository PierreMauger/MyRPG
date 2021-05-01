/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void displ_all(sfRenderWindow *window, raccoonmove_t *move, text_t *text)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, move->my_sprite, NULL);
    pnj(move);
    display_mykey(move, 0, 0);
    my_perso(window, move);
    if (move->obs.display_text_next == true)
        display_next_map(move);
    if (move->obs.display_text_back == true)
        display_back_map(move);
    if (text->clock)
        text_defil(move->sentence[text->str_index], text, window);
    if (move->chest.chest_open == true)
        chest_open(move);
    sfRenderWindow_display(window);
}

static void check_change_map(raccoonmove_t *move)
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
    raccoonmove_t move = init_struct_move(move, window);
    text_t text = init_text(text, &move);
    int passed = 0;

    if (move.obs.index_obs == -1)
        return (-1);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            map_event(&move, event, &passed, &text);
        }
        check_change_map(&move);
        ch_move(&move);
        displ_all(window, &move, &text);
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
