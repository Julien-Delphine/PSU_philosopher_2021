/*
** EPITECH PROJECT, 2021
** Philosophers
** File description:
** Start of the program after errors handle
*/

#include "philosphers.h"

void quitPhilo(philo_t *philo, arg_t *args)
{
    int i = 0;

    for (; i < args->philo - 1; i++)
        printf("ID: %d\nEat: %d\nRest:%d\nThink:%d\n\n", philo[i].id, 
        philo[i].action->eat, philo[i].action->rest, philo[i].action->think);
    printf("ID: %d\nEat: %d\nRest:%d\nThink:%d\n", philo[i].id, 
    philo[i].action->eat, philo[i].action->rest, philo[i].action->think);
    if (philo != NULL) {
        clearAction(philo);
        free(philo);
    }
    if (args != NULL)
        free(args);
}

int endThread(philo_t *philo)
{
    if (pthread_mutex_destroy(&philo->mutex) != 0)
        return (84);
    return (0);
}

int initThread(philo_t *philo, arg_t *args)
{
    for (int i = 0; i < args->philo; i++) {
        if (pthread_create(&philo[i].thread, NULL, philoLoop, &philo[i]))
            return (84);
    }
    for (int i = 0; i < args->philo; i++)
        pthread_join(philo[i].thread, NULL);
    return (endThread(philo));
}

int initPhilo(philo_t *philo, arg_t *args)
{
    philo->args = args;
    for (int i = 0; i != args->philo; i++) {
        philo[i].id = (i + 1);
        if (rand() % 2 == 0)
            philo[i].state = 0;
        else
            philo[i].state = 2;
        philo[i].timeEat = 0;
        philo[i].timeToEat = args->eat;
        philo[i].next = &philo[i + 1];
        pthread_mutex_init(&philo[i].mutex, NULL);
        initAction(philo, i);
    }
    philo[args->philo - 1].next = &philo[0];
    return (initThread(philo, args));
}

int startPhilo(arg_t *args)
{
    philo_t *philo = NULL;

    philo = malloc(sizeof(philo_t) * args->philo);
    if (philo == NULL)
        return (84);
    printf("%d philosophers can eat %d times\n\n", args->philo, args->eat);
    if (initPhilo(philo, args) == 84)
        return (84);
    quitPhilo(philo, args);
    return (0);
}