/*
** EPITECH PROJECT, 2022
** sbmlparser
** File description:
** main.c
*/

#include "sbmlparser.h"

void print_help(void)
{
    printf("USAGE\n\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n"
    "\nDESCRIPTION\n\tSBMLfile\tSBML file\n\t-i ID\t\tid "
    "of the compartment, reaction or product to be extracted\n"
    "\t\t\t(ignored if uncorrect)\n\t-e\t\tPrint the equa"
    "tion if a reaction ID is given as argument\n\t\t\t(ignor"
    "ed otherwise)\n\t-json\t\tTransform the file into a "
    "JSON file\n");
    exit(0);
}

void run(data_t *data)
{
    if (data->flag_i)
        id_parser(data);
    else
        simple_parser(data->filepath);
}

int main(int ac, char **av)
{
    data_t *data = get_flags(ac, av);

    run(data);
    return (0);
}
