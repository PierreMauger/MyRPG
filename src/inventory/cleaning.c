/*
** EPITECH PROJECT, 2021
** cleaning inventory once not needed anymore
** File description:
** cleaning
*/

#include "game.h"

void destroy_inv(inventory_t *inv)
{
    list_t *temp = inv->list;

    sfSprite_destroy(inv->equipedsprite);
    sfSprite_destroy(inv->invsprite);
    sfSprite_destroy(inv->selecsprite);
    sfTexture_destroy(inv->equipedtexture);
    sfTexture_destroy(inv->invtexture);
    sfTexture_destroy(inv->selectexture);
    for (; temp != NULL; temp = temp->next) {
        sfSprite_destroy(temp->data->sprite);
        sfTexture_destroy(temp->data->texture);
        free(temp->data->name);
        free(temp->data->description);
        free(temp->data);
    }
    list_destroy(inv->list);
    free(inv);
}