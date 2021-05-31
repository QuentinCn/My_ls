/*
** EPITECH PROJECT, 2020
** size_of
** File description:
** get the size of flags and file_list
*/

#include "../../include/my_ls.h"

int size_of_file_list(char **av)
{
    int len = 0;

    for (int i = 1; av[i]; i += 1) {
        if (av[i][0] != '-')
            len += 1;
    }
    if (len == 0)
        return (0);
    return (len);
}

int size_of_flags(t_list list, char **av)
{
    int size = 0;

    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][0] == '-') {
            for (int j = 1; av[i][j] != '\0'; j += 1) {
                size += 1;
            }
        }
    }
    return (size);
}

char **new_file_list(char **file_list, t_file *file)
{
    int i = 0;

    if (!file) {
        file_list[0] = NULL;
        return (file_list);
    }
    for (; file; i += 1, file = file->next) {
        file_list[i] = file->name;
    }
    file_list[i] = NULL;
    return (file_list);
}
