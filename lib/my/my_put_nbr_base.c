/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_put_nbr_base
*/

#include "my.h"

void my_put_nbr_oct(unsigned int nb)
{
    int i;
    int j;

    j = nb % 8;
    i = nb / 8;
    if (i != 0)
        my_put_nbr_oct(i);
    my_putchar(j + '0');
}

void my_put_nbr_hex(unsigned long int nb)
{
    unsigned long int i;
    unsigned long int j;

    j = nb % 16;
    i = nb / 16;
    if (i != 0)
        my_put_nbr_hex(i);
    if (j <= 9)
        my_putchar(j + '0');
    else
        my_putchar(j + 87);
}

void my_put_nbr_hex_maj(unsigned long int nb)
{
    unsigned long int i;
    unsigned long int j;

    j = nb % 16;
    i = nb / 16;
    if (i != 0)
        my_put_nbr_hex_maj(i);
    if (j <= 9)
        my_putchar(j + '0');
    else
        my_putchar(j + 55);
}

void my_put_nbr_bin(unsigned int nb)
{
    int i;
    int j;

    j = nb % 2;
    i = nb / 2;
    if (i != 0)
        my_put_nbr_bin(i);
    my_putchar(j + '0');
}

void my_put_nbr_uns(unsigned int nb)
{
    int i;
    int j;

    j = nb % 10;
    i = nb / 10;
    if (i != 0)
        my_put_nbr_uns(i);
    if (j <= 9)
        my_putchar(j + '0');
}