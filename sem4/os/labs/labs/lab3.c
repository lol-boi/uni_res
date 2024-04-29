#include <stdio.h>
#include <stdlib.h>

typedef struct p{
    int process_no;
    int arrival_time;
    int burst_time;
    int tat;
    int wt;
    int rt;
    int completion_time;
}process;

void input(process arr[], int count ){ 
    printf("Enter the arrival time and burst time one by one \n"); 
    int at;
    int bt;
    for(int i = 0; i<count; i++){
        scanf("%d %d", &at, &bt);
        //getchar(); 
        if(i == 0){ arr[i].process_no = (rand() % (99  - 10)) + 10;}
        else { arr[i].process_no = (arr[i-1].process_no) + 1;}
        arr[i].arrival_time = at;
        arr[i].burst_time = bt;
    }
}

void calc(process arr[], int size){
    int counter = 0;
    for(int i = 0; i<size; i++){
        if(counter < arr[i].arrival_time){
            counter = arr[i].arrival_time;
        }           
        arr[i].completion_time = counter + arr[i].burst_time;
        counter = arr[i].completion_time; 

    }
    for(int i =0; i<size; i++){
        arr[i].tat = arr[i].completion_time - arr[i].arrival_time;
        arr[i].wt = arr[i].tat - arr[i].burst_time;
        arr[i].rt = (arr[i].completion_time - arr[i].burst_time) - arr[i].arrival_time;
    }

}

int main(int argc, char *argv[])
{
    int count;
    scanf("%d", &count);
    process array[count];
    input(array,count);
    calc(array,count);    
    float avg_tat = 0;
    float avg_wt = 0 ;
    float avg_rt = 0 ;
    for(int i = 0; i<count; i++){
        avg_tat += array[i].tat;
        avg_wt += array[i].wt;
        avg_rt += array[i].rt;
    }
    printf("Average Turn Around Time: %f \n Average Waiting Time:  %f \n Average Response Time: %f \n", avg_tat/count , avg_wt/count, avg_rt/count);
 
    return 0;
}
