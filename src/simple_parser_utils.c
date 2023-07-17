/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** simple_parser_utils.c
*/

#include "sbmlparser.h"

void display_content(element_t *tmp)
{
    for (content_t *tmp2 = tmp->content; tmp2; tmp2 = tmp2->next)
        printf("--->%s\n", tmp2->name);
}

void display_only_args_elems(element_t *start)
{
    for (element_t *tmp = start; tmp; tmp = tmp->next) {
        if (tmp->content && tmp->disp == 0) {
            printf("%s\n", tmp->name);
            display_content(tmp);
            mark_as_displayed(start, tmp->name);
        }
    }
}
