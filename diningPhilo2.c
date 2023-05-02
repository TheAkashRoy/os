#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t chopstick[NUM_PHILOSOPHERS];

void eat(int id) {
    printf("Philosopher %d is eating...\n", id);
    sleep(rand() % 5);
}

void think(int id) {
    printf("Philosopher %d is thinking...\n", id);
    sleep(rand() % 5);
}

void take_chopsticks(int id, int left, int right) {
    if (id % 2 == 0) {
        sem_wait(&chopstick[left]);
        sem_wait(&chopstick[right]);
    } else {
        sem_wait(&chopstick[right]);
        sem_wait(&chopstick[left]);
    }
}

void put_chopsticks(int left, int right) {
    sem_post(&chopstick[right]);
    sem_post(&chopstick[left]);
}

void *philosopher_action(void *arg) {
    int id = (int)arg;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;
    while (1) {
        think(id);
        take_chopsticks(id, left, right);
        eat(id);
        put_chopsticks(left, right);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_t philosopher;
        pthread_create(&philosopher, NULL, philosopher_action, &i);
    }

    // Wait for signal to end program
    sigset_t signal_set;
    sigemptyset(&signal_set);
    sigsuspend(&signal_set);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}