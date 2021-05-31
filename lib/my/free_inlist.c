/*
** EPITECH PROJECT, 2020
** free_inlist
** File description:
** free a list
*/

#include "../../include/my_ls.h"

t_file *free_inlist(t_file *file)
{
    t_file *tmp = NULL;

    while (file) {
        tmp = file->next;
        free(file);
        file = tmp;
    }
    return (file);
}
