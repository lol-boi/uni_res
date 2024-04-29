#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int process_no;
    int tickets;
}lottery;

void input(lottery arr[], int count){
    for(int i = 0; i<count; i++){
        printf("Enter the tickets for process %d\n",i);
        scanf("%d", &arr[i].tickets);
        arr[i].process_no = i;
    }    
}

void l_scheduling(lottery arr[],int count, int a){
    int total = 0; 
    for(int i=0;i<count;i++){
        total += arr[i].tickets; 
    }
    printf("Scheduled Processes: ");
    for(int i = 0; i<a; i++){
        int rand_no = rand() % total + 1; //rand is deterministic so same value will be generated of the exact same input 
        int tmp = 0; 
        int counter = 0;
        do{
            tmp += arr[++counter].tickets;
        }while(tmp < rand_no);
        --counter;    
        printf("P%d ",counter);
    }
}

int main(int argc, char *argv[])
{
    int count;
    int allocation;
    printf("Enter no of process & allocation: ");
    scanf("%d %d",&count, &allocation);
    lottery arr[count]; 
    input(arr,count);
    l_scheduling(arr,count, allocation);
    return 0;
}
