/*
** EPITECH PROJECT, 2020
** do_in_dir
** File description:
** manage with directory
*/

#include "../../include/my_ls.h"

char *create_filename(char *filename, char *filepath, char *name)
{
    int i = 0;

    for (; filepath[i] != '\0'; i += 1)
        filename[i] = filepath[i];
    if (filename[i - 1] != '/') {
        filename[i] = '/';
        i += 1;
    }
    for (int j = 0; name[j] != '\0'; j += 1, i += 1)
        filename[i] = name[j];
    filename[i] = '\0';
    return (filename);
}

t_file *do_in_dir(t_file *file, t_list list, char *dir_name)
{
    DIR *dir;
    struct dirent *sd;
    char *filename;

    dir = opendir(dir_name);
    sd = readdir(dir);
    while (sd) {
        if (sd->d_name[0] != '.' && dir_name[0] == '.' && dir_name[1] == '\0') {
            file = give_name(file, sd->d_name);
        } else if (sd->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(dir_name) + \
            my_strlen(sd->d_name) + 2));
            filename = create_filename(filename, dir_name, sd->d_name);
            file = give_name(file, filename);
        }
        sd = readdir(dir);
    }
    return (file);
}

void display_in_dir(t_list list, char *dir_name)
{
    t_file *file = NULL;

    file = do_in_dir(file, list, dir_name);
    display_without_flag(file, list);
}

t_file *do_in_dir_with_l(t_file *file, t_list list, char *dir_name)
{
    DIR *dir;
    struct dirent *sd;
    char *filename;

    dir = opendir(dir_name);
    sd = readdir(dir);
    while (sd) {
        if (sd->d_name[0] != '.' && dir_name[0] == '.') {
            file = complete_file_l(file, sd->d_name);
        } else if (sd->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(dir_name) + \
            my_strlen(sd->d_name) + 2));
            filename = create_filename(filename, dir_name, sd->d_name);
            file = complete_file_l(file, filename);
        }
        sd = readdir(dir);
    }
    return (file);
}

void display_in_dir_with_l(t_list list, char *dir_name)
{
    t_file *file = NULL;

    file = do_in_dir_with_l(file, list, dir_name);
    display_with_l(file, list);
}
