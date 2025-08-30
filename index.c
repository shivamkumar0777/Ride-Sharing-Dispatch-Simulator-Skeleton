#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAXN 1024


typedef struct { int id; double x,y; double rating; int available; } Driver;
typedef struct { int id; double x,y; } Rider;


typedef struct { Driver *data[MAXN]; int sz; } MinHeap; 


typedef struct Node { int rideId; int driverId; int riderId; struct Node *next; } RideNode; // history queue





int main(){
    
    Driver drivers[MAXN];
    Rider riders[MAXN];
    MinHeap heap;
    heap.sz = 0;
    RideNode *history = NULL;

    drivers[0].id = 1;
    drivers[0].x = 10.0;
    drivers[0].y = 5.0;
    drivers[0].rating = 4.8;
    drivers[0].available = 1;

    riders[0].id = 1;
    riders[0].x = 12.0;
    riders[0].y = 6.0;

    heap.data[heap.sz++] = &drivers[0];

    RideNode *newRide = (RideNode*)malloc(sizeof(RideNode));
    newRide->rideId = 1;
    newRide->driverId = drivers[0].id;
    newRide->riderId = riders[0].id;
    newRide->next = history;
    history = newRide;

    printf("Driver %d assigned to Rider %d\n", drivers[0].id, riders[0].id);
return 0;
}