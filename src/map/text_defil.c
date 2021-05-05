/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "map.h"

static size_t spl_txt(size_t a, char *str, sfVector2f *pos, sfText *sen)
{
    int passed = 0;

    if (str[a] == '\0')
        passed++;
    if (str[a] == ' ' && passed == 0) {
        a++;
        passed++;
        pos->y += 55;
    }
    if (str[a - 1] == ' ' && passed == 0) {
        pos->y += 55;
        passed++;
    }
    if (passed == 0) {
        pos->x += 32;
        sfText_setPosition(sen, *pos);
        sfText_setString(sen, "-");
        pos->y += 55;
    }
    return (a);
}

static void display_text(char *str, sfRenderWindow *win, text_t *text, char *t)
{
    sfFont* font = sfFont_createFromFile("ressources/absender.ttf");
    sfText* sen = sfText_create();
    sfVector2f pos = text->pos;
    sfVector2f stock = pos;
    char c;

    pos.x += 10, sfText_setFont(sen, font);
    sfText_setCharacterSize(sen, text->size_font);
    for (size_t a = 0; a < bstrlen(str);) {
        c = str[a];
        sfText_setString(sen, &c), sfText_setPosition(sen, pos);
        sfRenderWindow_drawText(win, sen, NULL), a++;
        if (pos.x >= stock.x + (text->size_box.x - 100))
            a = spl_txt(a, t, &pos, sen), pos.x = stock.x + 10;
        else
            pos.x += 32;
        sfRenderWindow_drawText(win, sen, NULL);
    }
    sfText_destroy(sen);
    sfFont_destroy(font);
}

static void get_text(char *str, text_t *text, sfRenderWindow *window)
{
    size_t a = 0;

    if (text->save == NULL) {
        text->save = malloc(sizeof(char) * (bstrlen(str) + 1));
        text->save[0] = '\0';
    }
    if (sfClock_getElapsedTime(text->clock).microseconds >= text->delay
        && text->index < bstrlen(str)) {
        sfClock_restart(text->clock);
        text->index = text->index + 1;
    }
    for (;a != text->index; a++)
        text->save[a] = str[a];
    text->save[a] = '\0';
    display_text(text->save, window, text, str);
}

void text_defil(char *str, text_t *text, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = sfColor_fromRGBA(47, text->color2, text->color, 220);

    sfRectangleShape_setSize(rect, text->size_box);
    sfRectangleShape_setPosition(rect, text->pos);
    sfRectangleShape_setFillColor(rect, color);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
    get_text(str, text, window);
}

void my_init_text(text_t *text)
{
    text->index = 0;
    text->str_index = 0;
    text->clock = NULL;
    text->save = NULL;
    text->size_font = 60;
    text->pos.x = 100;
    text->pos.y = 680;
    text->size_box.x = 800;
    text->size_box.y = 200;
    text->delay = 50000;
    text->color = 12;
    text->color2 = 27;
    text->display = false;
}
