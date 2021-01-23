/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
