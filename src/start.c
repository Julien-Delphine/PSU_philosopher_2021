/*
** EPITECH PROJECT, 2021
** Philosophers
** File description:
** Start of the program after errors handle
*/

#include "philosphers.h"

void quitPhilo(philo_t *philo, arg_t *args)
{
    if (philo != NULL) {
        clearAction(philo);
        free(philo);
    }
    if (args != NULL)
        free(args);
}

void endThread(philo_t *philo)
{
    if (pthread_mutex_destroy(&philo->mutex) != 0)
        fprintf(stderr, "ERROR: Mutex destroy failed\n");
}

void initThread(philo_t *philo, arg_t *args)
{
    for (int i = 0; i < args->philo; i++) {
        if (pthread_create(&philo[i].thread, NULL, philoLoop, &philo[i]))
            fprintf(stderr, "ERROR: Thread creation failded\n");
    }
    for (int i = 0; i < args->philo; i++)
        pthread_join(philo[i].thread, NULL);
    endThread(philo);
}

int initPhilo(philo_t *philo, arg_t *args)
{
    philo->args = args;
    for (int i = 0; i != args->philo; i++) {
        philo[i].id = i;
        if (rand() % 2 == 0)
            philo[i].state = 0;
        else
            philo[i].state = 2;
        philo[i].timeEat = 0;
        philo[i].timeToEat = args->eat;
        philo[i].next = &philo[i + 1];
        philo[i].mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
        initAction(philo, i);
    }
    philo[args->philo - 1].next = &philo[0];
    initThread(philo, args);
    return (0);
}

int startPhilo(char **av)
{
    philo_t *philo = NULL;
    arg_t *args = malloc(sizeof(arg_t));

    if (args != NULL) {
        args->philo = atoi(av[2]);
        args->eat = atoi(av[4]);
    }
    philo = malloc(sizeof(philo_t) * args->philo);
    if (philo == NULL)
        return (84);
    initPhilo(philo, args);
    quitPhilo(philo, args);
    return (0);
}