/*
** EPITECH PROJECT, 2020
** navy
** File description:
** whit theo
*/

#include "map.h"

int	len(long nb)
{
    int	len = 0;

    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return (len);
}

char *my_itoa(int nb)
{
    char *str;
    long n = nb;
    int	i = len(n);

    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    str[i--] = '\0';
    if (n == 0) {
        str[0] = 48;
        return (str);
    }
    if (n < 0) {
        str[0] = '-';
        n = n * -1;
    }
    for (; n > 0; i--) {
        str[i] = 48 + (n % 10);
        n = n / 10;
    }
    return (str);
}
