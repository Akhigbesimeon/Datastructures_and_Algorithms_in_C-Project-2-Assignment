#include <stdio.h>
#include <string.h>
#include "heap.h"

// Swap two passengers in memory
static void swap(Passenger *a, Passenger *b) {
    Passenger temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify
static void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left].riskScore > heap->array[largest].riskScore)
        largest = left;

    if (right < heap->size && heap->array[right].riskScore > heap->array[largest].riskScore)
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

// Initialize heap function

void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

// Print heap
void printHeap(MaxHeap *heap) {
    printf("Current Priority Queue (Heap Structure):\n");
    if (heap->size == 0) {
        printf("  [Empty]\n");
        return;
    }
    for (int i = 0; i < heap->size; i++) {
        printf("  [%d] %s (Risk: %d)", i, heap->array[i].name, heap->array[i].riskScore);
        if (i == 0) printf(" <- ROOT (Next to Screen)");
        printf("\n");
    }
    printf("----------------------------------------\n");
}

// Build Max-Heap
void buildMaxHeap(MaxHeap *heap) {
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}

Passenger extractMax(MaxHeap *heap) {
    Passenger root = heap->array[0];
    if (heap->size <= 0) return root; // Should handle empty check in production

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    
    return root;
}

// Insert Passenger
void insertPassenger(MaxHeap *heap, char *name, int riskScore) {
    if (heap->size >= MAX_PASSENGERS) {
        printf("Error: Heap is full.\n");
        return;
    }

    int i = heap->size;
    strcpy(heap->array[i].name, name);
    heap->array[i].riskScore = riskScore;
    heap->size++;

    printf(">> INSERTING: %s (Risk: %d)\n", name, riskScore);

    while (i != 0 && heap->array[(i - 1) / 2].riskScore < heap->array[i].riskScore) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete passenger by score
void deletePassengerByScore(MaxHeap *heap, int targetScore) {
    int i;
    int found = 0;

    for (i = 0; i < heap->size; i++) {
        if (heap->array[i].riskScore == targetScore) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Passenger with score %d not found.\n", targetScore);
        return;
    }

    printf(">> REMOVING: %s (Risk: %d)\n", heap->array[i].name, heap->array[i].riskScore);

    heap->array[i] = heap->array[heap->size - 1];
    heap->size--;

    if (i > 0 && heap->array[i].riskScore > heap->array[(i - 1) / 2].riskScore) {
        while (i != 0 && heap->array[(i - 1) / 2].riskScore < heap->array[i].riskScore) {
            swap(&heap->array[i], &heap->array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    } else {
        maxHeapify(heap, i);
    }
}
