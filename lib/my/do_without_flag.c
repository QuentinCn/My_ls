/*
** EPITECH PROJECT, 2020
** do_without_flag
** File description:
** do my_ls without flag
*/

#include "../../include/my_ls.h"

t_file *give_name(t_file *file, char *filename)
{
    struct stat info;
    t_file *cell = malloc(sizeof(*cell));

    if (!stat(filename, &info)) {
        cell->type = find_type(info.st_mode);
        cell->name = filename;
    } else
        return (file);
    cell->next = file;
    return (cell);
}

t_file *do_without_flag(t_file *file, t_list list)
{
    if (list.file_list[0] != NULL) {
        for (int i = 0; list.file_list[i]; i += 1)
            file = give_name(file, list.file_list[i]);
    } else {
        file = malloc(sizeof(*file));
        file->name = ".";
        file->type = 'd';
        file->next = NULL;
    }
    return (file);
}
