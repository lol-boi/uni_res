
#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_REQUESTS 5

// Structure to represent a memory partition
struct Partition {
    int size;
    int allocated;
};

// Structure to represent a memory request
struct Request {
    int size;
    int allocated_partition_index;
};

int main() {
    struct Partition partitions[MAX_PARTITIONS];
    struct Request requests[MAX_REQUESTS];

    // Memory partition sizes
    int partition_sizes[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};

    // Process request sizes
    int request_sizes[MAX_REQUESTS] = {115, 500, 358, 200, 375};

    // Initialize partitions and requests
    initializePartitions(partitions, partition_sizes, MAX_PARTITIONS);
    initializeRequests(requests, request_sizes, MAX_REQUESTS);

    // Perform allocation using different algorithms
    printf("Best Fit Algorithm:\n");
    bestFit(partitions, requests, MAX_PARTITIONS, MAX_REQUESTS);
    printf("\nFirst Fit Algorithm:\n");
    firstFit(partitions, requests, MAX_PARTITIONS, MAX_REQUESTS);
    printf("\nNext Fit Algorithm:\n");
    nextFit(partitions, requests, MAX_PARTITIONS, MAX_REQUESTS);
    printf("\nWorst Fit Algorithm:\n");
    worstFit(partitions, requests, MAX_PARTITIONS, MAX_REQUESTS);

    return 0;
}

// Initialize partitions with given sizes
void initializePartitions(struct Partition partitions[], int sizes[], int num_partitions) {
    for (int i = 0; i < num_partitions; i++) {
        partitions[i].size = sizes[i];
        partitions[i].allocated = 0;
    }
}

// Initialize requests with given sizes
void initializeRequests(struct Request requests[], int sizes[], int num_requests) {
    for (int i = 0; i < num_requests; i++) {
        requests[i].size = sizes[i];
        requests[i].allocated_partition_index = -1;
    }
}

// Best Fit algorithm
void bestFit(struct Partition partitions[], struct Request requests[], int num_partitions, int num_requests) {
    for (int i = 0; i < num_requests; i++) {
        int best_fit_index = -1;
        int min_fragmentation = __INT_MAX__;
        for (int j = 0; j < num_partitions; j++) {
            if (!partitions[j].allocated && partitions[j].size >= requests[i].size) {
                int fragmentation = partitions[j].size - requests[i].size;
                if (fragmentation < min_fragmentation) {
                    min_fragmentation = fragmentation;
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index != -1) {
            partitions[best_fit_index].allocated = 1;
            requests[i].allocated_partition_index = best_fit_index;
        }
    }
    printAllocation(requests, num_requests);
}

// First Fit algorithm
void firstFit(struct Partition partitions[], struct Request requests[], int num_partitions, int num_requests) {
    for (int i = 0; i < num_requests; i++) {
        for (int j = 0; j < num_partitions; j++) {
            if (!partitions[j].allocated && partitions[j].size >= requests[i].size) {
                partitions[j].allocated = 1;
                requests[i].allocated_partition_index = j;
                break;
            }
        }
    }
    printAllocation(requests, num_requests);
}

// Next Fit algorithm
void nextFit(struct Partition partitions[], struct Request requests[], int num_partitions, int num_requests) {
    int last_allocated_index = 0;
    for (int i = 0; i < num_requests; i++) {
        for (int j = last_allocated_index; j < num_partitions; j++) {
            if (!partitions[j].allocated && partitions[j].size >= requests[i].size) {
                partitions[j].allocated = 1;
                requests[i].allocated_partition_index = j;
                last_allocated_index = j;
                break;
            }
        }
    }
    printAllocation(requests, num_requests);
}

// Worst Fit algorithm
void worstFit(struct Partition partitions[], struct Request requests[], int num_partitions, int num_requests) {
    for (int i = 0; i < num_requests; i++) {
        int worst_fit_index = -1;
        int max_fragmentation = -1;
        for (int j = 0; j < num_partitions; j++) {
            if (!partitions[j].allocated && partitions[j].size >= requests[i].size) {
                int fragmentation = partitions[j].size - requests[i].size;
                if (fragmentation > max_fragmentation) {
                    max_fragmentation = fragmentation;
                    worst_fit_index = j;
                }
            }
        }
        if (worst_fit_index != -1) {
            partitions[worst_fit_index].allocated = 1;
            requests[i].allocated_partition_index = worst_fit_index;
        }
    }
    printAllocation(requests, num_requests);
}

// Print allocation details
void printAllocation(struct Request requests[], int num_requests) {
    for (int i = 0; i < num_requests; i++) {
        printf("Request %d: ", i + 1);
        if (requests[i].allocated_partition_index != -1) {
            printf("Allocated to Partition %d\n", requests[i].allocated_partition_index + 1);
        } else {
            printf("Not allocated\n");
        }
    }
}
