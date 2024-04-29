#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int insert(int* &heap,int key){
    ++heap[0];
    int i = heap[0]; 
    heap = (int *) realloc(heap,sizeof(int) * (i+1));
    heap[i] = key;
    while(heap[i/2] < heap[i] && i > 1){
       int tmp = heap [i];
       heap[i] = heap[i/2];
       heap[i/2] = tmp;
       i = i/2;
    }
    return 1; 
}

int increase_key(int heap[],int i, int key){
    if(heap[i] > key ) return 0;
    heap[i] = key;
    while(heap[i/2] < heap[i] && i > 1){
       int tmp = heap [i];
       heap[i] = heap[i/2];
       heap[i/2] = tmp;
       i = i/2;
    }
    return 1;
}  
int heap_extract_max(int heap[]){
    if( heap[0] == NULL || heap[1] == NULL){
        cerr << "Empty heap" << endl;
    }
    return heap[1];
}

int main(){
    int *arr = (int*) malloc(6 * sizeof(int));
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 4;
    arr[3] = 2;
    arr[4] = 0;
    arr[5] = 1;
    heap_extract_max(arr);
    increase_key(arr,5,6);
    for(int i = 0; i<=5; i++) cout << arr[i] <<" ";
    insert(arr,15);
    insert(arr,5);
    for(int i = 0; i<=arr[0]; i++) cout << arr[i] <<" ";
    getchar();
    free(arr);
    return 0;

}
