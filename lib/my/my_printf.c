/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_printf
*/

#include "my.h"

static void loop(va_list list, char *s, int i)
{
    if (s[i + 1] == 'c') my_putchar(va_arg(list, int));
    if (s[i + 1] == 's') my_putstr(va_arg(list, char *));
    if (s[i + 1] == 'S') my_putstr_printable(va_arg(list, char *));
    if (s[i + 1] == 'd' || s[i + 1] == 'i') my_put_nbr(va_arg(list, int));
    if (s[i + 1] == 'b') my_put_nbr_bin(va_arg(list, unsigned int));
    if (s[i + 1] == 'u') my_put_nbr_uns(va_arg(list, unsigned int));
    if (s[i + 1] == 'o') my_put_nbr_oct(va_arg(list, unsigned int));
    if (s[i + 1] == 'x') my_put_nbr_hex(va_arg(list, unsigned int));
    if (s[i + 1] == 'X') my_put_nbr_hex_maj(va_arg(list, unsigned int));
    if (s[i + 1] == 'p') {
        my_putstr("0x");
        my_put_nbr_hex(va_arg(list, unsigned long int));
    }
    if (s[i + 1] == '%') my_putchar('%');
}

static void check_flags(char *s, int *i)
{
    while (s[*i + 1] == '#' || s[*i + 1] == ' ' || s[*i + 1] == '-' ||
    s[*i + 1] == '+' || s[*i + 1] == '0') {
        (*i)++;
    }
}

static void modulo(va_list list, char *s, int *i)
{
    check_flags(s, i);
    loop(list, s, *i);
}

int my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '%') {
            if (s[i + 1] != '\0') {
                modulo(list, s, &i);
                i++;
            }
        }
        else {
            my_putchar(s[i]);
        }
    }
    va_end(list);
    return (0);
}