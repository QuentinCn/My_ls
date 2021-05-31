/*
** EPITECH PROJECT, 2020
** len_list
** File description:
** get the len of a list
*/

#include "../../include/my_ls.h"

int len_list(t_file *file)
{
    int i = 0;

    for (; file; i += 1)
        file = file->next;
    return (i);
}
