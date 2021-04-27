/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static int create_sentence_pnj_split(raccoonmove_t *move, text_t *text)
{
    if (move->chest.nb_chest == 1) {
        move->sentence[0] = CHEST1_SPEAK_FIRST;
        move->sentence[1] = CHEST1_SPEAK_SECOND;
        move->chest.already_open_first = true;
        move->chest.my_texture = sfTexture_createFromFile
        ("ressources/sprites/sword.png", NULL);
    }
    if (move->chest.nb_chest == 2) {
        move->sentence[0] = CHEST2_SPEAK_FIRST;
        move->sentence[1] = CHEST2_SPEAK_SECOND;
        move->chest.already_open_second = true;
        move->chest.my_texture = sfTexture_createFromFile
        ("ressources/sprites/helm.png", NULL);
        move->boot = true;
    }
    move->sentence[2] = NULL;
}

int create_sentence_chest(raccoonmove_t *move, text_t *text)
{
    sfVector2f pos = move->raccoon_pos;

    if (move->chest.nb_chest == 1 && move->chest.already_open_first == true)
        return (1);
    if (move->chest.nb_chest == 2 && move->chest.already_open_second == true)
        return (1);
    move->chest.chest_open = true;
    move->sentence = malloc(sizeof(char *) * 3);
    create_sentence_pnj_split(move, text);
    move->chest.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->chest.my_sprite, move->chest.my_texture, sfTrue);
    pos.x += 70;
    sfSprite_setPosition(move->chest.my_sprite, pos);
    text->color = 120;
    text->size_box.x = 720;
    return (0);
}

int chest_open(raccoonmove_t *move, text_t *text)
{
    sfRenderWindow_drawSprite(move->window, move->chest.my_sprite, NULL);
    return (0);
}