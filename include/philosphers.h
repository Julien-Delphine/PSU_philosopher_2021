/*
** EPITECH PROJECT, 2021
** Philosphers
** File description:
** Include for philosophers
*/

#ifndef PHILOSOPHERS_H_
#define PHILOSOPHERS_H_

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct arg_s
{
    int philo;
    int eat;
} arg_t;

typedef struct philo_s
{
    int timeEat;
    int timeToEat;
    int state;
    int id;
    pthread_mutex_t mutex;
    pthread_t thread;
    arg_t *args;
    struct philo_s *next;
} philo_t;

void *philoLoop(void *philoArg);
void think(philo_t *philo, int a);
void eat(philo_t *philo, int a, int b);
void chillMan(philo_t *philo);
int startPhilo(char **av);

#endif