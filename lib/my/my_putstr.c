/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** display a string
*/

void my_putchar(char c);

int my_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
