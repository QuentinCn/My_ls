/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string
*/

#include "../../include/my_ls.h"

char *my_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i++];
    }
    dest[i] = '\0';
    return (dest);
}
