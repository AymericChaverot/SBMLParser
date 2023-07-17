/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** id_check.c
*/

#include "sbmlparser.h"

int id_exists2(data_t *data, element_t *tmp)
{
    for (content_t *content = tmp->content; content != NULL;
    content = content->next) {
        if (my_strcmp(content->name, "id") == 0 &&
            my_strcmp(content->value, data->flag_id) == 0) {
            data->flag_id_type = strdup(tmp->name);
            return (1);
        }
    }
    return (0);
}

int id_exists(data_t *data, element_t *list)
{
    element_t *tmp = list;

    while (tmp != NULL) {
        if (id_exists2(data, tmp))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
