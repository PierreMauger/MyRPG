/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Include
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char const *str);
void my_put_nbr(long int nb);
void my_put_nbr_uns(unsigned int nb);
void my_put_nbr_bin(unsigned int nb);
void my_put_nbr_oct(unsigned int nb);
void my_put_nbr_hex(unsigned long int nb);
void my_put_nbr_hex_maj(unsigned long int nb);
void my_putchar(char c);
void my_putstr(char *str);
void my_putstr_printable(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strndup(char const *src, int n);
char **str_to_word_array(char *str);
int my_printf(char *s, ...);
int simple_arg(char *filepath, struct stat file, int flag);
int multiple_arg(int argc, char **argv, struct stat file);
char *nbr_to_str(int nbr);

#endif
