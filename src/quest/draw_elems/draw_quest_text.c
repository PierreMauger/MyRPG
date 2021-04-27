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
    sfVector2f pos = game->qtext->pos;
    char c;

    pos.x += 10;
    sfText_setFont(game->qtext->text, game->font);
    sfText_setCharacterSize(game->qtext->text, game->qtext->size_font);
    for (int a = 0; str[a] != '\0'; a++) {
        c = str[a];
        sfText_setString(game->qtext->text, &c);
        sfText_setPosition(game->qtext->text, pos);
        sfRenderWindow_drawText(GET_WINDOW, game->qtext->text, NULL);
        if (pos.x >= game->qtext->size.x) {
            a = spl_txt(a, t, &pos, game->qtext->text);
            pos.x = game->qtext->pos.x + 10;
        }
        else
            pos.x += 32;
        sfRenderWindow_drawText(GET_WINDOW, game->qtext->text, NULL);
    }
}

static void get_text(char *str, game_t *game)
{
    game->qtext->save = malloc(sizeof(char) * (bstrlen(str) + 2));
    if (!(game->qtext->index >= bstrlen(str)))
        if (sfClock_getElapsedTime(game->time->clock).microseconds >=
        game->qtext->delay) {
        sfClock_restart(game->time->clock);
        game->qtext->index++;
    }
    for (size_t a = 0; a <= game->qtext->index; a++) {
        game->qtext->save[a] = str[a];
        game->qtext->save[a + 1] = '\0';
    }
    display_text(game->qtext->save, game, str);
    free(game->qtext->save);
}

void draw_quest_text(game_t *game)
{
    if (game->in_dialog == 1) {
        sfRenderWindow_drawRectangleShape(GET_WINDOW, game->qtext->rect, NULL);
        get_text(game->quest->start[game->qtext->str_index], game);
    }
}
