/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char *start = dest;
    int i = 0;

    while (*src && i < n) {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = '\0';
    return start;
}