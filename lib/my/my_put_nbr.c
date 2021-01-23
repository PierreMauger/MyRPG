/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_put_nbr
*/

#include "my.h"

void my_put_nbr(long nb)
{
    long i;
    long j;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        j = nb % 10;
        i = nb / 10;
        if (i != 0)
            my_put_nbr(i);
        my_putchar(j + '0');
    }
}
