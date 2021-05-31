/*
** EPITECH PROJECT, 2020
** find_mode
** File description:
** fonctions which help to find the type and permissions
*/

#include "../../include/my_ls.h"

char find_type(mode_t mode)
{
    switch (mode & S_IFMT) {
    case S_IFREG:
        return ('-');
    case S_IFDIR:
        return ('d');
    case S_IFCHR:
        return ('c');
    case S_IFBLK:
        return ('b');
    case S_IFIFO:
        return ('p');
    case S_IFLNK:
        return ('l');
    case S_IFSOCK:
        return ('s');
    default:
        return (0);
    }
}

int getoct(int nb)
{
    int octal = 0;
    int i = 10;

    octal += (nb % 8);
    nb /= 8;
    while (nb % 8 != 0) {
        octal += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    return (octal);
}

char *find_combination(int nb)
{
    switch (nb) {
    case 1:
        return ("--x");
    case 2:
        return ("-w-");
    case 3:
        return ("-wx");
    case 4:
        return ("r--");
    case 5:
        return ("r-x");
    case 6:
        return ("rw-");
    case 7:
        return ("rwx");
    default:
        return ("---");
    }
}

char *find_permission(mode_t mode)
{
    char *permission = malloc(sizeof(char) * 10);

    for (int i = 0; i != 3; i += 1) {
        permission[i] = find_combination(getoct(mode) / 100)[i];
    }
    for (int i = 0; i != 3; i += 1) {
        permission[i + 3] = find_combination(getoct(mode) / 10 % 10)[i];
    }
    for (int i = 0; i != 3; i += 1) {
        permission[i + 6] = find_combination(getoct(mode) % 10)[i];
    }
    permission[9] = '\0';
    return (permission);
}
