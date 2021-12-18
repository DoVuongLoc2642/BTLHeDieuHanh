#include <pthread.h>
#include <stdbool.h>

struct station {
    int free_seats; 
    int passengers_waiting; 
    int passengers_leaving; 
    pthread_mutex_t mutex;
    pthread_cond_t free_seats_available; 
    pthread_cond_t passengers_on_board; 
};

void station_init(struct station *station);

void station_load_train(struct station *station, int count);

void station_wait_for_train(struct station *station);

void station_on_board(struct station *station);
