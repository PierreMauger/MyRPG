/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 02/04/2021
*/

#include "barray.h"

void bfree_array(char **src)
{
    size_t len_src = barray_len((char **)src);

    if (!src)
        return;
    free(src);
}
    // for (int i = 0; i < (int)len_src; i++) {
    //     free(src[i]);
    // }
