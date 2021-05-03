/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void create_sentence_pnj_split(raccoonmove_t *move)
{
    if (move->chest.nb_chest == 1) {
        move->sentence[0] = CHEST1_SPEAK_FIRST;
        move->sentence[1] = CHEST1_SPEAK_SECOND;
        move->chest.already_open_first = true;
        move->chest.my_texture = sfTexture_createFromFile
        ("ressources/sprites/sword.png", NULL);
        move->item.sword = true;
    }
    if (move->chest.nb_chest == 2) {
        move->sentence[0] = CHEST2_SPEAK_FIRST;
        move->sentence[1] = CHEST2_SPEAK_SECOND;
        move->chest.already_open_second = true;
        move->chest.my_texture = sfTexture_createFromFile
        ("ressources/sprites/helm.png", NULL);
        move->item.boot = true;
    }
    move->anim = true;
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
    text->display = true;
    text->pos.x = move->raccoon_pos.x - 220;
    text->pos.y = move->raccoon_pos.y + 100;
    move->sentence = malloc(sizeof(char *) * 3);
    create_sentence_pnj_split(move);
    move->chest.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->chest.my_sprite, move->chest.my_texture, sfTrue);
    pos.x += 70;
    sfSprite_setPosition(move->chest.my_sprite, pos);
    text->color2 = 120;
    text->size_box.x = 720;
    return (0);
}

void chest_open(raccoonmove_t *move)
{
    sfRenderWindow_drawSprite(move->window, move->chest.my_sprite, NULL);
}

void climat_map(raccoonmove_t *move, text_t *text)
{
    move->pnj.exist = false;
    if (move->climat_change == false) {
        move->climat_change = true;
        text->display = true;
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = CLIMAT1_SPEAK_FIRST;
        move->sentence[1] = CLIMAT2_SPEAK_SECOND;
        move->sentence[2] = NULL;
        text->color2 = 0;
        text->pos.x = 200;
        text->size_box.x = 600;
        text->pos.x = move->raccoon_pos.x;
        text->pos.y = move->raccoon_pos.y + 100;
    }
}

void check_got_sword(raccoonmove_t *move, text_t *text)
{
    if (bstrcmp(MAP_OBS, MAP0) == 0 && move->item.sword == false) {
        text->display = true;
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = LINK_SPEAK_FIRST;
        move->sentence[1] = LINK_SPEAK_SECOND;
        move->sentence[2] = NULL;
        text->color = 120;
        text->size_box.x = 530;
    }
    if (bstrcmp(MAP_OBS, MAP2) == 0 && move->item.key == false) {
        text->display = true;
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = DONJON_SPEAK_FIRST;
        move->sentence[1] = DONJON_SPEAK_SECOND;
        move->sentence[2] = NULL;
        text->color = 120;
        text->size_box.x = 560;
    }
    text->pos.x = move->raccoon_pos.x - 220;
    text->pos.y = move->raccoon_pos.y + 100;
}
