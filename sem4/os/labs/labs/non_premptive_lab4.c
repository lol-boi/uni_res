#include <stdio.h>
#include <stdlib.h>

typedef struct p{
    int process_no;
    int arrival_time;
    int burst_time;
    int completion_time;
    int response_time;
    int turn_around_time;
    int waiting_time;
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

int compare_at(const void *a, const void *b){
    const process *x = (const process*)a; 
    const process *y = (const process*)b; 
    if(x->arrival_time < y->arrival_time){ return -1;}
    else if( x->arrival_time > y->arrival_time) {return 1;}
    else{ return 0;}
}

int compare_bt(const void *a, const void *b){
    const process *x = (const process*) a; 
    const process *y = (const process*)b;    
    if(x->burst_time < y->burst_time){return -1;}
    else if (x->burst_time > y->burst_time){return 1;}
    else{return 0;}
}

void sort(process arr[], int count){
    //first sort on the basis of burst time;
    qsort(arr,count,sizeof(process),compare_bt);
    //then sort on the bassis of arrival time
    qsort(arr,count,sizeof(process),compare_at);
}

void calc_non_premptive(process arr[], int size){
    int counter = 0;
    for(int i = 0; i<size; i++){
        if(counter < arr[i].arrival_time){
            counter = arr[i].arrival_time;
        }           
        arr[i].completion_time = counter + arr[i].burst_time;
        counter = arr[i].completion_time; 

    }
    for(int i =0; i<size; i++){
        arr[i].turn_around_time = arr[i].completion_time - arr[i].arrival_time;
        arr[i].waiting_time = arr[i].turn_around_time - arr[i].burst_time;
        arr[i].response_time = (arr[i].completion_time - arr[i].burst_time) - arr[i].arrival_time; //arr[i].turn_around_time - arr[i].burst_time;
    }

}

int main(){
    int count;
    scanf("%d", &count);
    process array[count];
    input(array,count); 
    sort(array,count);  
    calc_non_premptive(array,count);

    for(int  i = 0; i<count; i++){
        printf("%d %d %d %d %d %d\n", array[i].arrival_time, array[i].burst_time,array[i].completion_time, array[i].turn_around_time, array[i].waiting_time, array[i].response_time);
    } 
    
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

//non-premptive scheduling
