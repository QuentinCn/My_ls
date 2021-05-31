/*
** EPITECH PROJECT, 2020
** my_ls.c
** File description:
** show content about files
*/

#include "include/my_ls.h"

char **create_file_list(char **list, char **av)
{
    int j = 0;
    struct stat check;

    if (size_of_file_list(av) == 0) {
        list[0] = NULL;
        return (list);
    }
    for (int i = 1; av[i]; i += 1)
        if (av[i][0] != '-')
            if (!stat(av[i], &check)) {
                list[j] = av[i];
                j += 1;
            }
    list[j] = NULL;
    return (list);
}

int check_for_flag(char *flags, char c)
{
    for (int j = 0; flags[j] != '\0'; j += 1) {
        if (flags[j] == c)
            return (1);
    }
    return (0);
}

int my_ls(char **av)
{
    t_file *file = NULL;
    t_list list;

    list.flags = malloc(sizeof(char) * (size_of_flags(list, av) + 1));
    list.file_list = malloc(sizeof(char *) * (size_of_file_list(av) + 1));
    list = create_flags(list, av);
    list.file_list = create_file_list(list.file_list, av);
    if (check_for_flag(list.flags, 'd'))
        file = do_d(file, list);
    else if (check_for_flag(list.flags, 'l'))
        file = do_l(file, list);
    else
        file = do_without_flag(file, list);
    display(file, list);
    free_inlist(file);
    return (0);
}
