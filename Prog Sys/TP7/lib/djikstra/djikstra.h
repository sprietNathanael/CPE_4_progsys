#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>


int sem_create(key_t cle, int initval);
void P(int semid);
void V(int semid);
void sem_delete(int semid);

#endif