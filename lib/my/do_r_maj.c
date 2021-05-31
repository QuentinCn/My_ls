/*
** EPITECH PROJECT, 2020
** do_R
** File description:
** manage with R flag
*/

#include "../../include/my_ls.h"

int check_for_dir(t_file *file)
{
    while (file) {
        if (file->type == 'd')
            return (1);
        file = file->next;
    }
    return (0);
}

void do_in_dir_with_R(t_file *file, t_list list, char *dir_name)
{
    DIR *dir;
    struct dirent *sd;
    char *filename;
    t_file *new = NULL;

    dir = opendir(dir_name);
    sd = readdir(dir);
    while (sd) {
        if (sd->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(dir_name) + \
            my_strlen(sd->d_name) + 2));
            filename = create_filename(filename, dir_name, sd->d_name);
            new = give_name(new, filename);
        }
        sd = readdir(dir);
    }
    if (new)
        display_with_R(new, list);
}

void do_in_dir_with_Rl(t_file *file, t_list list, char *dir_name)
{
    DIR *dir;
    struct dirent *sd;
    char *filename;
    t_file *new = NULL;

    dir = opendir(dir_name);
    sd = readdir(dir);
    while (sd) {
        if (sd->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(dir_name) + \
            my_strlen(sd->d_name) + 2));
            filename = create_filename(filename, dir_name, sd->d_name);
            new = complete_file_l(new, filename);
        }
        sd = readdir(dir);
    }
    if (new)
        display_with_R(new, list);
}

void show_content(t_file *file, t_list list, char *dir_name)
{
    DIR *dir;
    struct dirent *sd;
    char *filename;
    t_file *new = NULL;

    dir = opendir(dir_name);
    sd = readdir(dir);
    while (sd) {
        if (sd->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(dir_name) + \
            my_strlen(sd->d_name) + 2));
            filename = create_filename(filename, dir_name, sd->d_name);
            if (check_for_flag(list.flags, 'l')) {
                new = complete_file_l(new, filename);
                do_display_with_l(new, list);
            } else {
                my_putstr(sd->d_name);
                my_putchar(' ');
            }
        }
        sd = readdir(dir);
    }
}

void display_with_R(t_file *file, t_list list)
{
    while (file) {
        if (file->type == 'd') {
            my_putstr(file->name);
            my_putstr(":\n");
            if (check_for_flag(list.flags, 'l')) {
                show_content(file, list, file->name);
                my_putchar(10);
                my_putchar(10);
                do_in_dir_with_Rl(file, list, file->name);
            } else {
                show_content(file, list, file->name);
                my_putchar(10);
                my_putchar(10);
                do_in_dir_with_R(file, list, file->name);
            }
        }
        file = file->next;
    }
}
