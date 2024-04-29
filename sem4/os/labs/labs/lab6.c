#include <stdio.h>
#include <stdlib.h>


typedef struct process {
    int priority;
    int p_no;
    int burst_time;
    int arrival_time;
    int response_time;
    int waiting_time;
    int turn_around_time;
    int comp_time;
}Process;


void input(Process arr[], int count ){ 
    printf("Enter the arrival time, burst time and priority of the pocesses one by one \n"); 
    int at;
    int bt;
    int p;
    for(int i = 0; i<count; i++){
        scanf("%d %d %d", &at, &bt, &p);
        //getchar(); 
        if(i == 0){ arr[i].p_no = (rand() % (99  - 10)) + 10;}
        else { arr[i].p_no = (arr[i-1].p_no) + 1;}
        arr[i].arrival_time = at;
        arr[i].burst_time = bt;
        arr[i].priority = p;
    }
}


void priority_scheduling(Process arr[], int size){
    int counter = 0;
    for(int i = 0; i<size; i++){
        if(counter < arr[i].arrival_time){
            counter = arr[i].arrival_time;
        }           
        arr[i].comp_time = counter + arr[i].burst_time;
        counter = arr[i].comp_time; 

    }
    for(int i =0; i<size; i++){
        arr[i].turn_around_time = arr[i].comp_time - arr[i].arrival_time;
        arr[i].waiting_time = arr[i].turn_around_time - arr[i].burst_time;
        arr[i].response_time = (arr[i].comp_time - arr[i].burst_time) - arr[i].arrival_time;
        printf("%d %d %d -- %d %d %d\n",arr[i].priority, arr[i].burst_time, arr[i].arrival_time, arr[i].turn_around_time, arr[i].waiting_time, arr[i].response_time); 
    }

}

int compare_at(const void *a, const void *b){
    const Process *x = (const Process*)a; 
    const Process *y = (const Process*)b; 
    if(x->arrival_time < y->arrival_time){ return -1;}
    else if( x->arrival_time > y->arrival_time) {return 1;}
    else{ return 0;}
}

int compare_priority(const void *a, const void *b){
    const Process *x = (const Process*)a;
    const Process *y = (const Process*)b;    
    if(x->priority < y->priority){return -1;}
    else if(x->priority > y->priority){return 1;}
    else {return 0;}
}
void sort(Process arr[], int count){
    //sort on the basis of priority;
    qsort(arr,count,sizeof(Process),compare_priority); 
    //then sort on the bassis of arrival time
    qsort(arr,count,sizeof(Process),compare_at);
    
}

int main(int argc, char *argv[])
{
    int count;
    scanf("%d", &count);
    Process array[count];
    input(array,count);
    sort(array, count);
    priority_scheduling(array,count);

    float avg_tat = 0;
    float avg_wt = 0 ;
    float avg_rt = 0 ;
    for(int i = 0; i<count; i++){
        avg_tat += array[i].turn_around_time;
        avg_wt += array[i].waiting_time;
        avg_rt += array[i].response_time;
    }
    printf("Average Turn Around Time: %f \n Average Waiting Time:  %f \n Average Response Time: %f \n", avg_tat/count , avg_wt/count, avg_rt/count); 
    return 0;
}
