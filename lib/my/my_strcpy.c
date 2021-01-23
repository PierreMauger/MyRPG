/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    char *start = dest;

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}