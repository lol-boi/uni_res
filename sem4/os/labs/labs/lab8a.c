//1. Write a program in C to implement the concept of variable sized partition use by the process request using Best fit, First Fit, Next Fit and Worst Fit algorithm.
//Use case: 
//Input: Consider six memory partition of 300 KB, 600 KB, 350 KB, 200 KB, 750 KB, and 125 KB (in order), 
//Process Request: 115 KB, 500 KB, 358 KB, 200 KB, and 375 KB (in order).
//Output: Allocation and rank which algorithm perform better in terms of internal fragmentation.

#include <stdio.h>
#include <stdlib.h>

void bestfit(int a[], int b[]){
    int a_size = 6; 
    int b_size = 5;
    int aux[a_size];
    for(int i = 0; i<a_size; i++){
        aux[i] = a[i];
    }
    for(int i = 0; i < b_size; i++){
        int smallest_par  = -1;
        for(int j = 0; j<a_size; j++){
            if(aux[j] >= b[i]){
                if(smallest_par == -1 || aux[j] < aux[smallest_par]){
                    smallest_par = j;
                }
            } 
        }
        if(smallest_par == -1){
            printf("Cannot find a sufficent partition for this process.\n");
        }else{
            aux[smallest_par] -= b[i];
            printf("The allocation is done in partition: %d\n", smallest_par);
        } 
            }
}


void firstfit(int a[], int b[]){
    int a_size = 6;
    int b_size = 5;
    int aux[a_size];
    for(int i = 0; i<a_size; i++){
        aux[i] = a[i];
    }
    for(int i = 0; i<b_size; i++){
        int par = -1; 
        for(int j = 0; j<a_size; j++){
            if(aux[j] >= b[i]){
                printf("The allocation is done in partition: %d\n", j);
                aux[j] -= b[i];
                par = 1;
                break;
            }
        }
        if(par == -1){
            printf("Cannot find a sufficent partition for this process \n");
        }
    }
} 
   
void worstfit(int a[], int b[]){
    int a_size = 6;
    int b_size = 5;
    int aux[a_size];
    for(int i = 0; i<a_size; i++){
        aux[i] = a[i];
    }
    for(int i = 0; i<b_size; i++){
        int par = -1;
        for(int j = 0; j<a_size; j++){
            if(aux[j] >= b[i]){
                if(par == -1 || aux[par] < aux[j]){
                    par = j;
                }
            }
        }
        if(par == -1) printf("Cannot find sufficent space to allocate this process. \n");
        else{
            printf("The allocation is don in partition: %d \n", par);
            aux[par] -= b[i];
        } 
    }
}

void nextfit(int a[], int b[]){
    int a_size = 6;
    int b_size = 5;
    int aux[a_size];
    for(int i = 0; i<a_size; i++){
        aux[i] = a[i];
    }
    int index = 0;
    for(int i = 0; i<b_size; i++){       
        while(1){
            if(index == a_size){
                index = 0;
            }
            if(aux[index++] >= b[i]){
                printf("The allocation is done in partition: %d\n", index);
                aux[index] -= b[i]; 
                break; 
            }
        }
    }
}

int main(int argc, char *argv[])
{ 
    int disk_ar[] = {300, 600, 350, 200, 750, 125};
    int process_req[] = {115, 500, 358, 200, 375};
    bestfit(disk_ar,process_req); 
    printf("\n");
    firstfit(disk_ar, process_req);
    printf("\n");
    worstfit(disk_ar, process_req);
    printf("\n");
    nextfit(disk_ar, process_req);
    
    return 0;
}
