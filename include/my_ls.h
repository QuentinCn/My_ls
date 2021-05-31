/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** .h of my ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <dirent.h>

#define ERROR 84

typedef struct file
{
    char type;
    char *permission;
    long int nb_link;
    char *user_ID;
    char *group_ID;
    long int size;
    char *date;
    char *name;
    struct file *next;
}t_file;

typedef struct list_info
{
    char *flags;
    char **file_list;
}t_list;

int my_strlen(char *str);
int my_putstr(char *str);
void my_putchar(char c);
int error_handling(int ac, char **av);
char find_type(mode_t mode);
int getoct(int nb);
char *find_combination(int nb);
char *find_permission(mode_t mode);
t_list create_flags(t_list list, char **av);
int my_ls(char **av);
int len_list(t_file *file);
long int my_put_nbr(long int nbr);
void display_without_flag(t_file *file, t_list list);
void display(t_file *file, t_list list);
t_file *give_name(t_file *file, char *filename);
t_file *do_without_flag(t_file *file, t_list list);
int check_for_flag(char *flags, char c);
t_file *do_in_dir(t_file *file, t_list list, char *dir_name);
void display_in_dir(t_list list, char *dir_name);
t_file *free_inlist(t_file *file);
int size_of_file_list(char **av);
int size_of_flags(t_list list, char **av);
char **new_file_list(char **file_list, t_file *file);
void display_with_l(t_file *file, t_list list);
void do_display_with_l(t_file *file, t_list list);
t_file *do_l(t_file *file, t_list list);
t_file *complete_file_l(t_file *file, char *filename);
t_file *do_in_dir_with_l(t_file *file, t_list list, char *dir_name);
void display_in_dir_with_l(t_list list, char *dir_name);
int check_in_file_list(char **file_list, char *name);
char *cut_name(char *name);
void multiple_folder(char **file_list, t_file *file, char *name);
t_file *do_d(t_file *file, t_list list);
void display_with_d(t_file *file, t_list list);
void display_with_R(t_file *file, t_list list);
char *create_filename(char *filename, char *dir_name, char *name);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char *src);
