#ifndef HEAP_H
#define HEAP_H

#define MAX_PASSENGERS 100

// Structure definitions
typedef struct {
    char name[50];
    int riskScore;
} Passenger;

typedef struct {
    Passenger array[MAX_PASSENGERS];
    int size;
} MaxHeap;

// Initializes the heap size to 0
void initHeap(MaxHeap *heap);

// prints the current state of the heap
void printHeap(MaxHeap *heap);

// Converts an existing array into a Max-Heap
void buildMaxHeap(MaxHeap *heap);

Passenger extractMax(MaxHeap *heap);

// Inserts a new passenger and maintains heap property
void insertPassenger(MaxHeap *heap, char *name, int riskScore);

// Removes a specific passenger by score
void deletePassengerByScore(MaxHeap *heap, int targetScore);

#endif
