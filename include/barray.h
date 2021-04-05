/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef BARRAY_H
#define BARRAY_H

#include "bstring.h"
#include "bmemory.h"

size_t barray_len(char **array);

char **binit_array_light(size_t x);
char **binit_array(size_t x, size_t y);

char **barray_dup(char **src);

char **bstr_array(char const *file, char separator);

char **badd_array(char **dest, char *src);

void bfree_array(char **src);

#endif // BARRAY_H
