/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static void create_sentence_chest_split(raccoonmove_t *move)
{
    char *buff = get_text_open("ressources/json/text.json");

    if (move->chest.nb_chest == 1) {
        move->sentence[0] = (char *)parser(buff, "chest1_speak_first", 1);
        move->sentence[1] = (char *)parser(buff, "chest1_speak_second", 1);
        move->chest.already_open_first = true;
        move->chest.my_texture = sfTexture_createFromFile(SWORD, NULL);
        move->item.sword = true;
    }
    if (move->chest.nb_chest == 2) {
        move->sentence[0] = (char *)parser(buff, "chest2_speak_first", 1);
        move->sentence[1] = (char *)parser(buff, "chest2_speak_second", 1);
        move->chest.already_open_second = true;
        move->chest.my_texture = sfTexture_createFromFile
        ("ressources/sprites/boots.png", NULL);
        move->item.boot = true;
    }
    free(buff);
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
    create_sentence_chest_split(move);
    move->chest.my_sprite = sfSprite_create();
    sfSprite_setTexture(move->chest.my_sprite, move->chest.my_texture, sfTrue);
    pos.x += 70;
    sfSprite_setPosition(move->chest.my_sprite, pos);
    create_mus("ressources/music/chest.ogg", &move->music.chest, 0);
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
    char *buff = NULL;

    move->pnj.exist = false;
    if (move->climat_change == false) {
        buff = get_text_open("ressources/json/text.json");
        move->climat_change = true;
        text->display = true;
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = (char *)parser(buff, "climat_speak_first", 1);
        move->sentence[1] = (char *)parser(buff, "climat_speak_second", 1);
        move->sentence[2] = NULL;
        text->color2 = 0;
        text->pos.x = 200;
        text->size_box.x = 600;
        text->pos.x = move->raccoon_pos.x;
        text->pos.y = move->raccoon_pos.y + 100;
        free(buff);
    }
}

void check_got_sword(raccoonmove_t *move, text_t *text)
{
    char *buff = get_text_open("ressources/json/text.json");

    if (bstrcmp(MAP_OBS, MAP0) == 0 && move->item.sword == false) {
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = (char *)parser(buff, "link_speak_first", 1);
        move->sentence[1] = (char *)parser(buff, "link_speak_second", 1);
        text->size_box.x = 530;
        move->sentence[2] = NULL;
        text->display = true;
    } if (bstrcmp(MAP_OBS, MAP2) == 0 && move->item.key == false) {
        move->sentence = malloc(sizeof(char *) * 3);
        move->sentence[0] = (char *)parser(buff, "donjon_speak_first", 1);
        move->sentence[1] = (char *)parser(buff, "donjon_speak_second", 1);
        text->size_box.x = 560;
        move->sentence[2] = NULL;
        text->display = true;
    }
    free(buff), text->color = 120;
    text->pos.x = move->raccoon_pos.x - 220;
    text->pos.y = move->raccoon_pos.y + 100;
}
