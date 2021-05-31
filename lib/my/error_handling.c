/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** manage with error
*/

#include "../../include/my_ls.h"

int error_handling(int ac, char **av)
{
    if (ac < 1)
        return (84);
    for (int i = 1; av[i] != NULL; i += 1) {
        for (int j = 1; av[i][j] != '\0' && av[i][0] == '-'; j += 1) {
            if (av[i][j] != 'l' && av[i][j] != 'R' && av[i][j] != 'd' && \
                av[i][j] != 'r' && av[i][j] != 't')
                return (ERROR);
        }
    }
    return (0);
}
