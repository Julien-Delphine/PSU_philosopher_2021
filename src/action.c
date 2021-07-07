/*
** EPITECH PROJECT, 2021
** Philosophers
** File description:
** action for philosopher
*/

#include "philosphers.h"

void takeChopstick(philo_t *philo, int a, int b)
{
    if (a == 0)
        pthread_mutex_lock(&philo->mutex);
    else if (b == 0)
        pthread_mutex_lock(&philo->next->mutex);
}

/*void giveChopstick(philo_t *philo)
{

}*/

void eat(philo_t *philo, int a, int b)
{
    (void)a;
    (void)b;
    pthread_mutex_lock(&philo->mutex);
    pthread_mutex_lock(&philo->next->mutex);
    philo->state = 1;
    //takeChopstick(philo, a, b);
    sleep(2);
    printf("ID: %d eat before end: %d\n", philo->id, philo->timeToEat - philo->timeEat);
    pthread_mutex_unlock(&philo->mutex);
    pthread_mutex_unlock(&philo->next->mutex);
}

void chillMan(philo_t *philo)
{
    sleep(2);
    printf("Relax: %d\n", philo->id);
    philo->state = 2;
}

void think(philo_t *philo, int a)
{
    pthread_mutex_lock(&philo->mutex);
    philo->state = 0;
    sleep(2);
    printf("Je pense donc je suis: %d\n", philo->id);
    if (a == 0)
        pthread_mutex_unlock(&philo->mutex);
    else
        pthread_mutex_unlock(&philo->next->mutex);
}