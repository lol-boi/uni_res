#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct process {
    int p_no;
    int burst_time;
    int remaining_time; 
    int arrival_time;
    int response_time;
    int waiting_time;
    int turn_around_time;
    int comp_time;
};
typedef struct process Process;

typedef struct queue {
    int index;
    Process* array[MAX];
} Queue;

void eneue(Queue* q, Process* p) {
    if (q->index >= MAX - 1) {
        printf("Not enough space to enqueue\n");
        return;
    }
    q->array[++(q->index)] = p;
}

Process* dequeue(Queue* q) {
    if (q->index == -1) {
        printf("Empty queue\n");
        return NULL;
    }
    Process* tmp = q->array[0];
    for (int i = 1; i <= q->index; i++) {
        q->array[i - 1] = q->array[i];
    }
    q->index--;
    return tmp;
}

void input(int count, Process* inp_array[]) {
    int at, bt;
    for (int i = 0; i < count; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &at, &bt);
        Process* p = malloc(sizeof(Process));
        p->arrival_time = at;
        p->burst_time = bt;
        p->remaining_time = bt;
        p->response_time = INT_MAX;
        inp_array[i] = p;
    }
}

int compare_at(const void* a, const void* b) {
    const Process* x = *(const Process**)a;
    const Process* y = *(const Process**)b;
    if (x->arrival_time < y->arrival_time) {
        return -1;
    } else if (x->arrival_time > y->arrival_time) {
        return 1;
    } else {
        return 0;
    }
}

void sort(Process* arr[], int count) {
    qsort(arr, count, sizeof(Process*), compare_at);
}

void roundrobinalgo(Process* arr[], int quantam, int count) {
    int time = 0;
    Queue q;
    q.index = -1;
    int index = 0;
    sort(arr, count);
    do {
        while (index < count && arr[index]->arrival_time <= time) {
            enqueue(&q, arr[index++]);     
        }
        if (q.index != -1) {
            if (time < q.array[0]->response_time) {
                q.array[0]->response_time = time;
            }
            printf("%d %d | ", q.array[0]->remaining_time, q.array[0]->arrival_time);
            q.array[0]->remaining_time -= quantam;
            if (q.array[0]->remaining_time <= 0) {
                q.array[0]->comp_time = time + quantam + q.array[0]->remaining_time; 
                arr[0]->turn_around_time = arr[0]->comp_time - arr[0]->arrival_time;
                arr[0]->waiting_time = arr[0]->turn_around_time - q.array[0]->burst_time;               
                dequeue(&q);
            } else {
                enqueue(&q, dequeue(&q));
            }
        } else {
            printf("Idle | ");
        }
        time += quantam;
    } while (q.index != -1 || index < count);
    printf("\n");
}

void calc(Process* arr[], int size) {
    int tat = 0;
    int rt = 0;
    int wt = 0;
    for(int i = 0; i<size; i++){
        tat += arr[i]->burst_time;
        rt += arr[i]->response_time;
        wt += arr[i]->waiting_time;
    }
    printf("Avg turn_around_time: %d\nAvg response_time: %d \nAvg waiting_time: %d \n", tat/size, rt/size, wt/size);
}

int main(int argc, char* argv[]) {
    printf("NOTE: The algo only check for new processes after the specified time quantum,\nSo there will be also some idle time left in come cases\n\n\n");
    int count, time_q;
    printf("Enter the no of process and the time quantum: ");
    scanf("%d %d", &count, &time_q);

    Process* inp_array[count];
    input(count, inp_array);
    roundrobinalgo(inp_array, time_q, count);
    calc(inp_array, count);
    return 0;
}
