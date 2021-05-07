/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static void check_pos_parallax(game_t *game)
{
    if (game->menu->para->pos_para.mont.x <= -1920)
        game->menu->para->pos_para.mont.x = 1920;
    if (game->menu->para->pos_para.sky.x <= -1920)
        game->menu->para->pos_para.sky.x = 1920;
    if (game->menu->para->pos_para.tree.x <= -1920)
        game->menu->para->pos_para.tree.x = 1920;
    if (game->menu->para->pos_para.grass.x <= -1920)
        game->menu->para->pos_para.grass.x = 1920;
    if (game->menu->paracpy->pos_para.mont.x <= -1920)
        game->menu->paracpy->pos_para.mont.x = 1920;
    if (game->menu->paracpy->pos_para.sky.x <= -1920)
        game->menu->paracpy->pos_para.sky.x = 1920;
    if (game->menu->paracpy->pos_para.tree.x <= -1920)
        game->menu->paracpy->pos_para.tree.x = 1920;
    if (game->menu->paracpy->pos_para.grass.x <= -1920)
        game->menu->paracpy->pos_para.grass.x = 1920;
}

static void display_parallax_split(game_t *game)
{
    sfRenderWindow_drawSprite(GET_WINDOW, game->menu->para->sprite_sky, NULL);
    sfRenderWindow_drawSprite(
        GET_WINDOW, game->menu->paracpy->sprite_sky, NULL);
    sfRenderWindow_drawSprite(GET_WINDOW, game->menu->para->sprite_mont, NULL);
    sfRenderWindow_drawSprite(
        GET_WINDOW, game->menu->paracpy->sprite_mont, NULL);
    sfRenderWindow_drawSprite(GET_WINDOW, game->menu->para->sprite_tree, NULL);
    sfRenderWindow_drawSprite(
        GET_WINDOW, game->menu->paracpy->sprite_tree, NULL);
    sfRenderWindow_drawSprite(GET_WINDOW, game->menu->para->sprite_grass, NULL);
    sfRenderWindow_drawSprite(
        GET_WINDOW, game->menu->paracpy->sprite_grass, NULL);
    game->menu->para->pos_para.mont.x -= game->menu->para->speed.mont;
    game->menu->para->pos_para.sky.x -= game->menu->para->speed.sky;
    game->menu->para->pos_para.tree.x -= game->menu->para->speed.tree;
    game->menu->para->pos_para.grass.x -= game->menu->para->speed.grass;
    game->menu->paracpy->pos_para.mont.x -= game->menu->paracpy->speed.mont;
    game->menu->paracpy->pos_para.sky.x -= game->menu->paracpy->speed.sky;
    game->menu->paracpy->pos_para.tree.x -= game->menu->paracpy->speed.tree;
    game->menu->paracpy->pos_para.grass.x -= game->menu->paracpy->speed.grass;
}

void display_parallax(game_t *game)
{
    sfSprite_setPosition(game->menu->para->sprite_sky,
        game->menu->para->pos_para.sky);
    sfSprite_setPosition(game->menu->para->sprite_grass,
        game->menu->para->pos_para.grass);
    sfSprite_setPosition(game->menu->para->sprite_tree,
        game->menu->para->pos_para.tree);
    sfSprite_setPosition(game->menu->para->sprite_mont,
        game->menu->para->pos_para.mont);
    sfSprite_setPosition(game->menu->paracpy->sprite_sky,
        game->menu->paracpy->pos_para.sky);
    sfSprite_setPosition(game->menu->paracpy->sprite_grass,
        game->menu->paracpy->pos_para.grass);
    sfSprite_setPosition(game->menu->paracpy->sprite_tree,
        game->menu->paracpy->pos_para.tree);
    sfSprite_setPosition(game->menu->paracpy->sprite_mont,
        game->menu->paracpy->pos_para.mont);
    display_parallax_split(game);
    check_pos_parallax(game);
}

static parallax_t *init_speed_pos_parallax(parallax_t *para, int pos_max)
{
    para->sprite_tree = sfSprite_create();
    sfSprite_setTexture(
        para->sprite_tree, para->tree, sfFalse);
    para->speed.sky = 0.5;
    para->speed.mont = 1.5;
    para->speed.tree = 3;
    para->speed.grass = 4;
    para->pos_para.sky.x = pos_max;
    para->pos_para.sky.y = 0;
    para->pos_para.mont.x = pos_max;
    para->pos_para.mont.y = 0;
    para->pos_para.tree.x = pos_max;
    para->pos_para.tree.y = 0;
    para->pos_para.grass.x = pos_max;
    para->pos_para.grass.y = 0;
    return (para);
}

parallax_t *init_parallax(parallax_t *para, int pos_max)
{
    para = malloc(sizeof(parallax_t) * 1);
    para->sky = sfTexture_createFromFile(
        "ressources/parallax/sky.png", NULL);
    para->grass = sfTexture_createFromFile(
        "ressources/parallax/grass.png", NULL);
    para->tree = sfTexture_createFromFile(
        "ressources/parallax/tree.png", NULL);
    para->mont = sfTexture_createFromFile(
        "ressources/parallax/mont.png", NULL);
    para->sprite_sky = sfSprite_create();
    sfSprite_setTexture(para->sprite_sky, para->sky, sfFalse);
    para->sprite_mont = sfSprite_create();
    sfSprite_setTexture(
        para->sprite_mont, para->mont, sfFalse);
    para->sprite_grass = sfSprite_create();
    sfSprite_setTexture(
        para->sprite_grass, para->grass, sfFalse);
    para = init_speed_pos_parallax(para, pos_max);
    return (para);
}