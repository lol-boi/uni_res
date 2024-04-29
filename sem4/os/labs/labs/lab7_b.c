#include <stdio.h>
#include <stdlib.h>

typedef struct lot {
    char process;
    int tickets;
    int stride_val;
}lottery;

void input(lottery arr[], int count){
    char c = 'a'; 
    for(int i = 0; i<count; i++){
        printf("Enter the tickets for process %c\n",c+i);
        scanf("%d", &arr[i].tickets);
        arr[i].stride_val = 0;  
        arr[i].process = c+i; 
    }    
}

void s_scheduling(lottery arr[], int count, int allocation){
    printf("Schelduling: \n");
    int counter = 1; 
    while(counter++ < allocation){
        lottery *min = &arr[0]; 
        for(int i = 0; i<count; i++){
            if( min->stride_val >  arr[i].stride_val){
                min = &arr[i]; 
            }
        }
        printf("%c \n", min->process);
        min->stride_val = min->stride_val + min->tickets;
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
    s_scheduling(arr,count, allocation); 
    return 0;
}
