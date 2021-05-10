/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

void check_map_sound_go(raccoonmove_t *move)
{
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) != 0
        && move->music.snow != NULL) {
        sfMusic_destroy(move->music.snow);
        move->music.snow = NULL;
    }
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) != 0
        && move->music.rain != NULL) {
        sfMusic_destroy(move->music.rain);
        move->music.rain = NULL;
    }
}

void check_map_sound(raccoonmove_t *move)
{
    if (bstrcmp(move->obs.fl_map_obstacle, MAP2) == 0)
        create_mus("ressources/music/snow.ogg", &move->music.snow, 1);
    if (bstrcmp(move->obs.fl_map_obstacle, MAP1) == 0)
        create_mus("ressources/music/rain.ogg", &move->music.rain, 1);
    move->obs.next_map = false;
}

void create_mus(char *filepath, sfMusic **music, int loop)
{
    *music = sfMusic_createFromFile(filepath);
    if (loop == 1)
        sfMusic_setLoop(*music, sfTrue);
    sfMusic_play(*music);
}

void music_dest(raccoonmove_t *move, int i)
{
    if (move->music.chest) {
        sfMusic_destroy(move->music.chest);
        move->music.chest = NULL;
    }
    if (move->music.rain && i == 1) {
        sfMusic_destroy(move->music.rain);
        move->music.rain = NULL;
    }
    if (move->music.snow && i == 1) {
        sfMusic_destroy(move->music.snow);
        move->music.snow = NULL;
    }
}

void init_music(raccoonmove_t *move)
{
    move->music.chest = NULL;
    move->music.snow = NULL;
    move->music.rain = NULL;
    create_mus("ressources/music/theme.ogg", &move->music.theme, 1);
    sfMusic_setVolume(move->music.theme, (float)50);
}
