/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** elements_list.c
*/

#include "sbmlparser.h"

element_t *create_elem(element_t *start, char *full_tag)
{
    element_t *new = malloc(sizeof(element_t));
    element_t *tmp = start;
    new->content = get_content(full_tag);
    new->name = extract_name(full_tag);
    new->marks_end = (full_tag[0] == '/') ? 1 : 0;
    new->orphan = (full_tag[strlen(full_tag) - 1] == '/') ? 1 : 0;
    new->next = NULL;
    if (start == NULL)
        return (new);
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
    return (start);
}

element_t *delete_elem(element_t *start)
{
    element_t *tmp = start;

    if (start == NULL)
        return (NULL);
    start = start->next;
    free(tmp->name);
    free(tmp->content);
    free(tmp);
    return (start);
}

element_t *make_list(char **tags)
{
    element_t *list = NULL;
    int i = 1;

    while (tags[i] != NULL) {
        list = create_elem(list, tags[i]);
        i++;
    }
    return (list);
}
