/*
** EPITECH PROJECT, 2020
** main
** File description:
** main my_ls
*/

#include "include/my_ls.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av))
        return (84);
    my_ls(av);
}
