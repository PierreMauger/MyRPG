/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void get_xp(mons_t *mons)
{
    char *buffer = bread_file(JSON_MONS, 20);
    int fd = open(JSON_MONS, O_RDWR);

    for (mons_t *temp = mons; temp; temp = temp->next) {
        temp->stat->xp += 50;
        if (temp->stat->xp > 100) {
            temp->stat->xp = 1;
            temp->stat->level++;
            buffer = parser_write(buffer, "level",
            bitoa(temp->stat->level), temp->id);
            buffer = level_up(buffer, temp);
        }
        buffer = parser_write(buffer, "xp", bitoa(temp->stat->xp), temp->id);
    }
    write(fd, buffer, bstrlen(buffer));
    free(buffer);
}

char *level_up(char *buffer, mons_t *mons)
{
    mons->stat->att += 10;
    mons->stat->def += 10;
    mons->stat->speed += 1;
    buffer = parser_write(buffer, "att", bitoa(mons->stat->att), mons->id);
    buffer = parser_write(buffer, "def", bitoa(mons->stat->def), mons->id);
    buffer = parser_write(buffer, "speed", bitoa(mons->stat->speed), mons->id);
    return buffer;
}
