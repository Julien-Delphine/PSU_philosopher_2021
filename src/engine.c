/*
** EPITECH PROJECT, 2021
** Philosopher
** File description:
** Engine for philosopher
*/

#include "philosphers.h"

/*void checkState(philo_t *philo, int a, int b)
{
    if (philo->state == 2) {
        a = pthread_mutex_trylock(&philo->mutex);
        if (a != 0)
            b = pthread_mutex_trylock(&philo->next->mutex);
        if (a == 0 || b == 0)
            think(philo, a, b);
    }
}*/

void checkAction(philo_t *philo)
{
    int a = 0;
    int b = 0;

    if (philo->state == 0) {
        eat(philo, a, b);
        philo->timeEat++;
    }
    else if (philo->state == 2)
        think(philo, a);
    else
        chillMan(philo);
}

void *philoLoop(void *philoArg)
{
    philo_t *philo = philoArg;

    for (; philo->timeEat < philo->timeToEat;)
        checkAction(philo);
    printf("G fini\n");
    return (0);
}