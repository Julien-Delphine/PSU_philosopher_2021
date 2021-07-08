/*
** EPITECH PROJECT, 2021
** Philosophers
** File description:
** Main for philosophers
*/

#include "philosphers.h"

void printHelp()
{
    printf("USAGE\n");
    printf("\t./philo -p nbr_p -e nbr_e\n\n");
    printf("DESCRIPTION\n");
    printf("\t-p nbr_p  number of philosophers\n");
    printf("\t-e nbr_e  maximum number times a philosopher eats ");
    printf("before exiting the program\n");
}

int overflow(arg_t *args)
{
    if (args->philo > __INT_MAX__)
        return (84);
    else if (args->eat > __INT_MAX__)
        return (84);
    return (0);
}

int verifNumber(char **av, arg_t *args)
{
    if (atoi(av[2]) && atoi(av[4])) {
        args->philo = atoi(av[2]);
        args->eat = atoi(av[4]);
        if (args->philo <= 1)
            return (84);
        else if (args->eat <= 0)
            return (84);
        return (0);
    }
    if (overflow(args) == 84)
        return (84);
    return (84);
}

int handleArg(int ac, char **av, arg_t *args)
{
    int check = 0;

    if (ac == 2) {
        if (!strcmp(av[1], "--help"))
            printHelp();
        else
            return (84);
    }
    if (ac != 5)
        return (84);
    else {
        if (!strcmp(av[1], "-p") && !strcmp(av[3], "-e"))
            check = verifNumber(av, args);
        else
            return (84);
    }
    return (check);
}

int main(int ac, char **av)
{
    arg_t *args = malloc(sizeof(arg_t));

    if (args == NULL)
        return (84);
    if (handleArg(ac, av, args) == 84)
        return (84);
    else
        if (startPhilo(args) == 84)
            return (84);
    return (0);
}