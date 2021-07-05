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
    printf("\t-e nbr_e  maximum number times a philosopher eats before exiting the program\n");
}

int verifNumber(char **av)
{
    if (atoi(av[2]) && atoi(av[4])) {
        printf("%s philosophers can eat %s times\n", av[2], av[4]);
        return (0);
    }
    return (84);
}

int handleArg(int ac, char **av)
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
            check = verifNumber(av);
        else
            return (84);
    }
    return (check);
}

int main(int ac, char **av)
{
    if (handleArg(ac, av) == 84)
        return (84);
    return (0);
}