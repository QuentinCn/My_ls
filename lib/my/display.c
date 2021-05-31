/*
** EPITECH PROJECT, 2020
** display
** File description:
** display file
*/

#include "../../include/my_ls.h"

int check_in_file_list(char **file_list, char *name)
{
    for (int i = 0; file_list[i]; i += 1) {
        if (file_list[i] == name)
            return (1);
    }
    return (0);
}

char *cut_name(char *name)
{
    int place = -1;

    for (int i = 0; name[i] != '\0'; i += 1){
        if (name[i] == '/')
            place = i;
    }
    name = &name[place + 1];
    return (name);
}

void multiple_folder(char **file_list, t_file *file, char *name)
{
    int i = 0;
    int k = 0;

    for (int j = 0; file_list[j]; j += 1) {
        if (file->type == 'd')
            i += 1;
    }
    while (file) {
        if (file->type == 'd')
            k += 1;
        file = file->next;
    }
    if (k != i) {
        my_putchar(10);
        my_putchar(10);
    }
    if (i > 1) {
        my_putstr(name);
        my_putstr(":\n");
    }
}

void display_without_flag(t_file *file, t_list list)
{
    while (file) {
        if (list.file_list[0] == NULL && file->type == 'd' && len_list(file) \
            == 1) {
            display_in_dir(list, file->name);
        }
        else if (list.file_list[0] != NULL && \
        check_in_file_list(list.file_list, file->name) \
        && file->type == 'd') {
            multiple_folder(list.file_list, file, file->name);
            display_in_dir(list, file->name);
        } else {
            my_putstr(cut_name(file->name));
            my_putstr("  ");
        }
        file = file->next;
    }
}

void display(t_file *file, t_list list)
{
    if (check_for_flag(list.flags, 'd'))
        display_with_d(file, list);
    else if (check_for_flag(list.flags, 'R'))
        display_with_R(file, list);
    else if (check_for_flag(list.flags, 'l'))
        display_with_l(file, list);
    else
        display_without_flag(file, list);
    my_putchar(10);
}
