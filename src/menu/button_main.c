button_system.c                                                                                     0000644 0001750 0001750 00000001601 14044444735 013170  0                                                                                                    ustar   mhugo                           mhugo                                                                                                                                                                                                                  /*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

void draw_buttons(button_t **list, game_t *game)
{
    if (list == NULL || game == NULL)
        return;
    for (unsigned int itr = 0; list[itr]; ++itr) {
        sfRenderWindow_drawSprite(GET_WINDOW, list[itr]->sprite, NULL);
    }
}

void set_btn_pos(button_t *btn, sfVector2f pos)
{
    if (!btn)
        return;
    btn->pos = pos;
    sfSprite_setPosition(btn->sprite, btn->pos);
}

void draw_button(game_t *game, button_t *btn)
{
    sfRenderWindow_drawSprite(GET_WINDOW, btn->sprite, NULL);
}

void set_button_rect(button_t *btn, sfIntRect rect)
{
    if (!btn)
        return;
    sfSprite_setTextureRect(btn->sprite, rect);
}

void set_button_color(button_t *btn, sfColor color)
{
    if (!btn)
        return;
    btn->color = color;
    sfSprite_setColor(btn->sprite, color);
}                                                                                                                               main_menu.c                                                                                         0000644 0001750 0001750 00000006076 14044444735 012234  0                                                                                                    ustar   mhugo                           mhugo                                                                                                                                                                                                                  /*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

void move_bg(sfSprite *spr, int spd, struct game_object *obj)
{
    sfClock *clock;
    clock = sfClock_create();
    sfTime time;
    float seconds; 
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0f;
    if (seconds >= 0) {
        sfSprite_getPosition(spr);
        sfClock_restart(clock);
        obj->r.left += spd;
        if (obj->r.left >= 1920)
            obj->r.left = 0;
        sfSprite_setTextureRect(spr, obj->r);
    }
    return;
}

struct game_object *create_object(const char *path, sfVector2f pos, sfIntRect r)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, r);
    struct game_object *obj = malloc(sizeof(struct game_object));
    obj->texture = texture;
    obj->sprite = sprite;
    obj->pos = pos;
    obj->r = r;
    obj->count_jump = 0;
    return (obj);
}

void display_menu(struct game_object **tab, int nbr_assets, game_t *game)
{
    //sfText *txt = create_text_btn(txt, game);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW);
    for (int i = 0; i < nbr_assets; i++) {
        move_bg(tab[i]->sprite, tab[i]->speed, tab[i]);
    }
    sfVector2f pos = btn->text_pos;
    for (int j = 0; j < nbr_assets; ++j) {
        sfRenderWindow_drawSprite(GET_WINDOW, tab[j]->sprite, NULL);
    }
    sfRectangleShape *shape;
    display_shape_block(shape, game, NULL);
        /*if (mouse.x >= pos.x && mouse.y >= pos.y && mouse.x <= pos.x + 300 && mouse.y <= pos.y + 300)
            set_color(txt, sfRed);*/
    /*if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            if (mouse.x >= pos.x && mouse.y >= pos.y && mouse.x <= pos.x + 300 && mouse.y <= pos.y + 300)
                exit(0);*/
}

void display_shape_block(sfRectangleShape *shape, game_t *game, sfText *txt)
{
    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, (sfVector2f){400, 1080});
    sfRectangleShape_setFillColor(shape, (sfColor){255, 255,255, 200});
    sfRectangleShape_setPosition(shape, (sfVector2f){300, 0});
    sfRenderWindow_drawRectangleShape(GET_WINDOW, shape, NULL);
    //create_text_btn(txt, game);
}

struct game_object **obj_n(int nbr_assets)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 1920, 1080};
    struct game_object **tab = malloc(sizeof(struct game_object) * nbr_assets);
    tab[0] = create_object("layer06_sky.png", pos, rect);
    tab[1] = create_object("layer05_rocks.png", pos, rect);
    tab[2] = create_object("layer04_clouds.png", pos, rect);
    tab[3] = create_object("layer03_trees.png", pos, rect);
    tab[4] = create_object("layer02_cake.png", pos, rect);
    tab[5] = create_object("layer01_ground.png", pos, rect);
    tab[1]->speed = 2;
    tab[2]->speed = 2;
    tab[3]->speed = 3;
    tab[4]->speed = 5;
    tab[5]->speed = 8;
    return (tab);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  menu_button_part.c                                                                                  0000644 0001750 0001750 00000000731 14044444735 013641  0                                                                                                    ustar   mhugo                           mhugo                                                                                                                                                                                                                  /*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

sfText *create_text_btn(sfText *txt, game_t *game, button_t *btn)
{
    txt = init_font(txt, (sfVector2f){330, 60}, "./ressources/font.ttf", "MENU");
    set_size_font(txt, 100);
    set_color(txt, sfBlack);
    show_font(game, txt);
    sfVector2f pos;
    btn->f_rect = sfText_getGlobalBounds(txt);
    btn->text_pos = sfText_getPosition(txt);
    return (txt);
}                                       system_font.c                                                                                       0000644 0001750 0001750 00000001305 14044444735 012624  0                                                                                                    ustar   mhugo                           mhugo                                                                                                                                                                                                                  /*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"
#include <button.h>

sfText *init_font(sfText *txt, sfVector2f pos, char *font, char *text)
{
    txt = sfText_create();
    sfFont *menu = sfFont_createFromFile(font);
    if (!menu)
        return;
    sfText_setPosition(txt, pos);
    sfText_setString(txt, text);
    sfText_setFont(txt, menu);
    return (txt);
    //sfText_destroy(txt);
}

void set_size_font(sfText *txt, unsigned int size)
{
    sfText_setCharacterSize(txt, size);
}

void set_color(sfText *txt, sfColor color)
{
    sfText_setColor(txt, color);
}

void show_font(game_t *game, sfText *txt)
{
    sfRenderWindow_drawText(GET_WINDOW, txt, NULL);
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           