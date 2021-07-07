/*
** EPITECH PROJECT, 2021
** Philosophers
** File description:
** action for philosopher
*/

#include "philosphers.h"

void initAction(philo_t *philo, int i)
{
    philo[i].action = malloc(sizeof(action_t));
    if (philo[i].action != NULL) {
        philo[i].action->eat = 0;
        philo[i].action->rest = 0;
        philo[i].action->think = 0;
    }
}

void clearAction(philo_t *philo)
{
    for (int i = 0; i < philo->args->philo; i++) {
        if (philo[i].action != NULL)
            free (philo[i].action);
    }
}

void eat(philo_t *philo)
{
    philo->state = 1;
    sleep(2);
    philo->action->eat++;
    philo->timeEat++;
    pthread_mutex_unlock(&philo->mutex);
    pthread_mutex_unlock(&philo->next->mutex);
}

void chillMan(philo_t *philo)
{
    sleep(2);
    philo->action->rest++;
    philo->state = 2;
}

void think(philo_t *philo, int a)
{
    philo->state = 0;
    sleep(2);
    philo->action->think++;
    if (a == 0)
        pthread_mutex_unlock(&philo->mutex);
    else
        pthread_mutex_unlock(&philo->next->mutex);
}