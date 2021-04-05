/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static int spl_txt(int a, char *str, sfVector2f *pos, sfText *sen)
{
    int passed = 0;

    if (str[a] == ' ') {
        a++, passed++, pos->y += 55;
    }
    if (str[a - 1] == ' ' && passed == 0) {
        pos->y += 55, passed++;
    }
    if (passed == 0) {
        pos->x += 32;
        sfText_setPosition(sen, *pos);
        sfText_setString(sen, "-");
        pos->y += 55;
    }
    return a;
}

static void display_text(char *str, game_t *game, char *t)
{
    sfVector2f pos = (sfVector2f){180, 300};
    sfVector2f stock = pos;
    char c;

    pos.x += 10, sfText_setFont(game->text->text, game->font);
    sfText_setCharacterSize(game->text->text, 60);
    for (int a = 0; str[a] != '\0'; a++) {
        c = str[a];
        sfText_setString(game->text->text, &c);
        sfText_setPosition(game->text->text, pos);
        sfRenderWindow_drawText(GET_WINDOW, game->text->text, NULL);
        if (pos.x >= 600) {
            a = spl_txt(a, t, &pos, game->text->text);
            pos.x = stock.x + 10;
        }
        else
            pos.x += 32;
        sfRenderWindow_drawText(GET_WINDOW, game->text->text, NULL);
    }
}

static void get_text(char *str, game_t *game)
{
    game->text->save = malloc(sizeof(char) * (bstrlen(str) + 1));
    if (!(game->text->index >= bstrlen(str)))
        if (sfClock_getElapsedTime(game->time->clock).microseconds >=
        game->text->delay) {
        sfClock_restart(game->time->clock);
        game->text->index++;
    }
    for (size_t a = 0; a <= game->text->index; a++) {
        game->text->save[a] = str[a];
        game->text->save[a + 1] = '\0';
    }
    display_text(game->text->save, game, str);
    free(game->text->save);
}

void draw_quest_text(game_t *game)
{
    if (game->in_dialog == 1) {
        sfRenderWindow_drawRectangleShape(GET_WINDOW, game->text->rect, NULL);
        get_text(game->quest->start[game->text->str_index], game);
    }
}
