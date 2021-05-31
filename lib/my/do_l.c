/*
** EPITECH PROJECT, 2020
** do_l
** File description:
** manage with l flag
*/

#include "../../include/my_ls.h"

t_file *complete_file_l(t_file *file, char *filename)
{
    struct stat info = {0};
    t_file *cell = malloc(sizeof(*cell));

    if (!stat(filename, &info)) {
        cell->type = find_type(info.st_mode);
        cell->permission = find_permission(info.st_mode);
        cell->nb_link = info.st_nlink;
        cell->user_ID = getpwuid(info.st_uid)->pw_name;
        cell->group_ID = getgrgid(info.st_gid)->gr_name;
        cell->size = info.st_size;
        cell->date = my_strdup(ctime(&info.st_ctime));
        cell->date = &cell->date[4];
        cell->date[13] = '\0';
        cell->name = filename;
    }
    cell->next = file;
    return (cell);
}

t_file *do_l(t_file *file, t_list list)
{
    if (list.file_list[0] != NULL) {
        for (int i = 0; list.file_list[i]; i += 1)
            file = complete_file_l(file, list.file_list[i]);
    } else {
        file = malloc(sizeof(*file));
        file->name = ".";
        file->type = 'd';
        file->next = NULL;
    }
    return (file);
}

void do_display_with_l(t_file *file, t_list list)
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
    my_putstr(cut_name(file->name));
    my_putchar(10);
}

void display_with_l(t_file *file, t_list list)
{
    while (file) {
        if (list.file_list[0] == NULL && file->type == 'd' && len_list(file) \
            == 1) {
            display_in_dir_with_l(list, file->name);
        } else if (list.file_list[0] != NULL && \
        check_in_file_list(list.file_list, file->name) && file->type == 'd') {
            multiple_folder(list.file_list, file, file->name);
            display_in_dir_with_l(list, file->name);
        } else {
            do_display_with_l(file, list);
        }
        file = file->next;
    }
}
