/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** change_bool
*/

void change_bool(int *value)
{
    if (*value == 0)
        *value = 1;
    else
        *value = 0;
}