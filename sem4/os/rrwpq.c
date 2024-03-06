
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct {
    int pid;
    int burst_time;
    int priority;
} Process;

// Priority queue node structure
typedef struct {
    Process process;
    struct Node* next;
} Node;

// Priority queue structure
typedef struct {
    Node* front;
    Node* rear;
} PriorityQueue;

// Initialize empty priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = pq->rear = NULL;
    return pq;
}

// Check if priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->front == NULL;
}

// Enqueue process into priority queue based on priority
void enqueue(PriorityQueue* pq, Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->process = process;
    newNode->next = NULL;

    if (isEmpty(pq)) {
        pq->front = pq->rear = newNode;
        return;
    }

    Node* current = pq->front;
    Node* prev = NULL;
    while (current != NULL && current->process.priority <= process.priority) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

// Dequeue process from priority queue
Process dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = pq->front;
    Process process = temp->process;
    pq->front = pq->front->next;

    if (pq->front == NULL) {
        pq->rear = NULL;
    }

    free(temp);
    return process;
}

// Round Robin scheduling with priority queue
void roundRobinWithPriority(Process processes[], int n, int time_quantum) {
    PriorityQueue* ready_queue = createPriorityQueue();

    int current_time = 0;
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
        enqueue(ready_queue, processes[i]);
    }

    while (!isEmpty(ready_queue)) {
        Process current_process = dequeue(ready_queue);
        printf("Executing process %d with priority %d at time %d\n", current_process.pid, current_process.priority, current_time);

        if (remaining_burst_time[current_process.pid - 1] > time_quantum) {
            current_time += time_quantum;
            remaining_burst_time[current_process.pid - 1] -= time_quantum;
            enqueue(ready_queue, current_process);
        } else {
            current_time += remaining_burst_time[current_process.pid - 1];
            remaining_burst_time[current_process.pid - 1] = 0;
            printf("Process %d completed at time %d\n", current_process.pid, current_time);
        }
    }

    printf("All processes completed.\n");
}

int main() {
    Process processes[] = {
        {1, 10, 3},
        {2, 5, 1},
        {3, 8, 2}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 2;
    roundRobinWithPriority(processes, n, time_quantum);
    return 0;
}
