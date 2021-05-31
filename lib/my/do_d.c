/*
** EPITECH PROJECT, 2020
** do_d
** File description:
** manage d flag
*/

#include "../../include/my_ls.h"

t_file *do_d(t_file *file, t_list list)
{
    if (list.file_list[0] != NULL) {
        if (!check_for_flag(list.flags, 'l')) {
            for (int i = 0; list.file_list[i]; i += 1)
                file = give_name(file, list.file_list[i]);
        } else
            for (int i = 0; list.file_list[i]; i += 1)
                file = complete_file_l(file, list.file_list[i]);
    } else {
        if (!check_for_flag(list.flags, 'l')) {
            file = malloc(sizeof(*file));
            file->name = ".";
            file->next = NULL;
        } else
            file = complete_file_l(file, ".");
    }
    return (file);
}

void do_display_with_ld(t_file *file, t_list list)
{
    my_putchar(file->type);
    my_putstr(file->permission);
    my_putchar(' ');
    my_put_nbr(file->nb_link);
    my_putchar(' ');
    my_putstr(file->user_ID);
    my_putchar(' ');
    my_putstr(file->group_ID);
    my_putchar(' ');
    my_put_nbr(file->size);
    my_putchar(' ');
    my_putstr(file->date);
    my_putchar(' ');
    my_putstr(file->name);
    if (file->next)
        my_putchar(10);
}

void display_with_d(t_file *file, t_list list)
{
    while (file) {
        if (check_for_flag(list.flags, 'l')) {
            do_display_with_ld(file, list);
        } else if (list.file_list[0] == NULL && file->type == 'd' && \
        len_list(file) == 1) {
            my_putstr(".");
        } else {
            my_putstr(file->name);
            my_putstr("  ");
        }
        file = file->next;
    }
}
