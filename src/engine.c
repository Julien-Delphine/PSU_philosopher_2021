/*
** EPITECH PROJECT, 2021
** Philosopher
** File description:
** Engine for philosopher
*/

#include "philosphers.h"

void checkState(philo_t *philo, int a, int b)
{
    if (philo->state == 2) {
        a = pthread_mutex_trylock(&philo->mutex);
        if (a != 0)
            b = pthread_mutex_trylock(&philo->next->mutex);
        if (a == 0 || b == 0)
            think(philo, a);
    }
}

void checkAction(philo_t *philo)
{
    int a = 0;
    int b = 0;

    if (philo->state == 0) {
        a = pthread_mutex_trylock(&philo->mutex);
        b = pthread_mutex_trylock(&philo->next->mutex);
        if (a == 0 && b == 0)
            eat(philo);
        else if (b != 0 && a == 0)
            pthread_mutex_unlock(&philo->mutex);
        else if (a != 0 && b == 0)
            pthread_mutex_unlock(&philo->next->mutex);
    }
    else if (philo->state == 1)
        chillMan(philo);
    else
        checkState(philo, a, b);
}

void *philoLoop(void *philoArg)
{
    philo_t *philo = philoArg;

    for (; philo->timeEat != philo->timeToEat;)
        checkAction(philo);
    printf("ID: %d\nEat: %d\nRest:%d\nThink:%d\n\n", 
    philo->id, philo->action->eat, philo->action->rest, philo->action->think);
    return (0);
}