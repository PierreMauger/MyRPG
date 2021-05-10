/*
** EPITECH PROJECT, 2021
** inv funcs to handle inv events
** File description:
** inv_events
*/

#include "game.h"

static void set_equiped(inventory_t *inv, int index)
{
    list_t *temp = inv->list;

    while (temp != NULL) {
        if (temp->data->index == index && temp->data->is_equiped == false)
            temp->data->is_equiped = true;
        else if (temp->data->index == index && temp->data->is_equiped == true)
            temp->data->is_equiped = false;
        temp = temp->next;
    }
    free(temp);
}

void draw_equiped(game_t *game, inventory_t *inv)
{
    list_t *temp = inv->list;
    sfVector2f pos;
    pos.y = inv->pos.y + 3.f;

    while (temp != NULL) {
        if (temp->data->is_equiped == true) {
            pos.x = temp->data->pos.x;
            sfSprite_setPosition(inv->equipedsprite, pos);
            sfRenderWindow_drawSprite(GET_WINDOW, inv->equipedsprite, NULL);
        }
        temp = temp->next;
    }
    free(temp);
}

void set_selec_pos(inventory_t *inv)
{
    sfVector2f pos;
    pos.x = (inv->pos.x + 3.f) + (70 * inv->selected);
    pos.y = inv->pos.y + 3.f;
    sfSprite_setPosition(inv->selecsprite, pos);
}

void poll_key_pressed(game_t *game, inventory_t *inv)
{
    if (game->event.key.code == sfKeyDash && sfKeyboard_isKeyPressed(sfKeyNum9))
        add_item_to_inv(inv, 1);
    if (game->event.key.code == sfKeyI)
        game->in_inv = false;
    if (game->event.key.code == sfKeyRight && inv->selected < 4)
        inv->selected += 1;
    if (game->event.key.code == sfKeyLeft && inv->selected != 0)
        inv->selected -= 1;
    if (game->event.key.code == sfKeyEnter)
        set_equiped(inv, inv->selected);
    if (game->event.key.code == sfKeyH && inv->prompt == false)
        inv->prompt = true;
    else if (game->event.key.code == sfKeyH && inv->prompt == true)
        inv->prompt = false;
}

int poll_inv_events(game_t *game, inventory_t *inv)
{
    while (sfRenderWindow_pollEvent(GET_WINDOW, &game->event)) {
        if (game->event.type == sfEvtKeyPressed)
            poll_key_pressed(game, inv);
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(GET_WINDOW);
            return 1;
        }
    }
    return 0;
}