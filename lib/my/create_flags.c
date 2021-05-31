/*
** EPITECH PROJECT, 2020
** create
** File description:
** create different things
*/

#include "../../include/my_ls.h"

t_list create_flags(t_list list, char **av)
{
    int k = 0;

    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][0] == '-' && av[i][1] >= 'a' && av[i][1] <= 'z' || \
            av[i][1] == 'R') {
            for (int j = 1; av[i][j] != '\0'; j += 1) {
                list.flags[k] = av[i][j];
                k += 1;
            }
        }
    }
    list.flags[k] = '\0';
    return (list);
}
