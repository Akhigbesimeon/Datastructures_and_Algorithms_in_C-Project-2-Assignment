#include <stdio.h>
#include "heap.h"

// Main Function
int main() {
    MaxHeap airportQueue;
    initHeap(&airportQueue);

    // Initial Data Load
    Passenger initialBatch[] = {
        {"Alice", 45}, {"Brian", 75}, {"Chen", 20},
        {"Fatima", 85}, {"Noah", 60}, {"Sofia", 30}
    };
    int n = sizeof(initialBatch) / sizeof(initialBatch[0]);

    printf("-- INITIALIZING SECURITY SYSTEM --\n");
    for(int i = 0; i < n; i++) {
        airportQueue.array[i] = initialBatch[i];
    }
    airportQueue.size = n;
    
    // Build Max-Heap
    buildMaxHeap(&airportQueue);
    printf("Status: Initial Max-Heap Built.\n");
    printHeap(&airportQueue);

    // New passenger arrival (risk score 98)
    printf("-- NEW PASSENGER ARRIVAL --\n");
    insertPassenger(&airportQueue, "Thadee", 98);
    printHeap(&airportQueue);

    // Passenger with risk score 98 is cleared and removed
    printf("-- PASSENGER CLEARED --\n");
    deletePassengerByScore(&airportQueue, 98);
    printHeap(&airportQueue);

    return 0;
}
