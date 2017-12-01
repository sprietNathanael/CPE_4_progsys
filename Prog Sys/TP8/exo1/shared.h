#ifndef SHARED_H
#define SHARED_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "dijkstra/dijkstra.h"
#include "log/log.h"

#define ENTRY_MAX_LEN 5
#define SIZE_BUFFER ENTRY_MAX_LEN+2
#define SHM_CLE 123
#define MUTEX_CLE 456
#define SEM_PROD_CLE 78
#define SEM_CONSO_CLE 89

#endif
