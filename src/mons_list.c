/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

static data_mons_t data_mons[] = {
    {'a', 130, 255, 60, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 5, "abc"},
    {'b', 150, 230, 255, 0, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 8, "ade"},
    {'c', 150, 0, 170, 255, LANCER_IMG, LANCER_IMG_COLOR, 260, 252, 4, 7, "afg"},
    {'d', 150, 255, 255, 255, SLIME_IMG, SLIME_IMG_COLOR, 66, 50, 3, 2, "abc"}
};

int find_in_mons_database(char name)
{
    for (int i = 0; i < 4; i++)
        if (data_mons[i].name == name)
            return i;
    return 0;
}

void init_mons_texture(mons_t *element, sfVector2f pos, int i)
{
    element->mons_tex = malloc(sizeof(mons_texture_t));
    element->mons_tex->rect = (sfIntRect){0, 0, data_mons[i].width, data_mons[i].height};
    element->mons_tex->nb_anim = data_mons[i].nb_anim;
    element->mons_tex->texture = sfTexture_createFromFile(data_mons[i].sprite, NULL);
    element->mons_tex->sprite = sfSprite_create();
    element->mons_tex->texture_color = sfTexture_createFromFile(data_mons[i].sprite_color, NULL);
    element->mons_tex->sprite_color = sfSprite_create();
    sfSprite_setOrigin(element->mons_tex->sprite, (sfVector2f){element->mons_tex->rect.width / 2, element->mons_tex->rect.height});
    sfSprite_setOrigin(element->mons_tex->sprite_color, (sfVector2f){element->mons_tex->rect.width / 2, element->mons_tex->rect.height});
    sfSprite_setPosition(element->mons_tex->sprite, pos);
    sfSprite_setPosition(element->mons_tex->sprite_color, pos);
    sfSprite_setColor(element->mons_tex->sprite_color, sfColor_fromRGB(data_mons[i].red, data_mons[i].green, data_mons[i].blue));
}

void init_mons_stat(mons_t *element, sfVector2f pos, int i)
{
    element->mons_stat = malloc(sizeof(mons_stat_t));
    element->mons_stat->max_hp = data_mons[i].hp;
    element->mons_stat->curr_hp = element->mons_stat->max_hp;
    element->mons_stat->hp = sfRectangleShape_create();
    sfRectangleShape_setOrigin(element->mons_stat->hp, (sfVector2f){element->mons_tex->rect.width / 2 + 50, 0});
    sfRectangleShape_setSize(element->mons_stat->hp, (sfVector2f){100, 10});
    sfRectangleShape_setFillColor(element->mons_stat->hp, sfGreen);
    sfRectangleShape_setPosition(element->mons_stat->hp, (sfVector2f){pos.x + element->mons_tex->rect.width / 2, pos.y + 10});
    element->mons_stat->speed = data_mons[i].speed;
    element->mons_stat->atb_value = 0;
    element->mons_stat->atb = sfRectangleShape_create();
    sfRectangleShape_setOrigin(element->mons_stat->atb, (sfVector2f){element->mons_tex->rect.width / 2 + 50, 0});
    sfRectangleShape_setSize(element->mons_stat->atb, (sfVector2f){0, 10});
    sfRectangleShape_setFillColor(element->mons_stat->atb, sfCyan);
    sfRectangleShape_setPosition(element->mons_stat->atb, (sfVector2f){pos.x + element->mons_tex->rect.width / 2, pos.y + 30});
}

void put_in_mons_list(mons_t **mons, sfVector2f pos, char name, game_t *game)
{
    mons_t *element = malloc(sizeof(mons_t));
    mons_t *last = *mons;
    int i = find_in_mons_database(name);

    init_mons_texture(element, pos, i);
    init_mons_stat(element, pos, i);
    element->skill = NULL;
    for (int j = 0; data_mons[i].skill[j]; j++)
        put_in_skill_list(&element->skill, data_mons[i].skill[j], game);
    element->next = NULL;

    if (*mons == NULL) {
        element->next = *mons;
        *mons = element;
    }
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = element;
    }
}
