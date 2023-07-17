/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** readfile.c
*/

#include "sbmlparser.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat st;

    if (fd == -1)
        exit(84);
    stat(filepath, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    if (read(fd, buffer, st.st_size) < 0)
        exit(84);
    close(fd);
    return (buffer);
}
