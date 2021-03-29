/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#ifndef BSTRING_H
#define BSTRING_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t bstrlen(char const *str);

void *bmemset(void *s, int c, size_t n);

int bstrcmp(const char *s1, const char *s2);
int bstrncmp(const char *s1, const char *s2, size_t n);

char *bstrdup(char const *src);
char *bstrndup(char const *src, size_t n);

char *bstrcat(char *dest, char const *src);
char *bstrncat(char *dest, char const *src, size_t n);

char *bstrcpy(char *dest, char const *src);
char *bstrncpy(char *dest, char const *src, size_t n);

char *brevstr(char *src);

char *bitoa(int nbr);
int batoi(char *str);

#endif // BSTRING_H
