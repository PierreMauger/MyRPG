/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

static void three_digits(int nb)
{
    if (nb < 8)
        my_putstr("00");
    else if (nb < 80)
        my_putstr("0");
}

void my_putstr_printable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] < ' ' || str[i] > '~'))
            write(1, &str[i], 1);
        else {
            my_putchar('\\');
            three_digits(str[i]);
            my_put_nbr_oct(str[i]);
        }
    }
}