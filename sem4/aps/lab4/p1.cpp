#include <iostream>
#include <iterator>
using namespace std;

void merge(int* array, int beg, int mid, int end){
    //this initial condition is very imp. for creation of array   
    int arr_size_l = mid - beg + 1;
    int arr_size_r = end - mid;

    int tmp_arr_l[arr_size_l];
    int tmp_arr_r[arr_size_r];
    int tmp = 0;
    
    for(int i = beg; i<=mid; i++){
        tmp_arr_l[tmp++] = array[i];
    }
    
    tmp = 0;
    
    for(int i = mid+1; i<=end; i++){
        tmp_arr_r[tmp++] = array[i];
    }
    
    int tmp_l = 0, tmp_r = 0;
    tmp = beg;
    
    while(tmp_l < arr_size_l && tmp_r < arr_size_r){
        if(tmp_arr_l[tmp_l] <= tmp_arr_r[tmp_r]){
            array[tmp++] = tmp_arr_l[tmp_l++]; 
        }
        else{
            array[tmp++] = tmp_arr_r[tmp_r++];
        }
    }

    while(tmp_l < arr_size_l){
        array[tmp++] = tmp_arr_l[tmp_l++];
    }
    while(tmp_r < arr_size_r){
        array[tmp++]  = tmp_arr_r[tmp_r++];
    }
}
void merge_sort(int* array, int beg, int end){
    if(beg >= end){
        return;
    }
        int mid = (end + beg)/2; 
        merge_sort(array,beg,mid);
        merge_sort(array,mid+1, end);
        merge(array,beg,mid,end);
}

void solve(int array[], int size){
    int min = array[size-1]; 
    int a, b;
    for(int i =0; i<size-1; i++){
        if(array[i+1] - array[i] < min){
            min = array[i+1] - array[i];
            a = array[i];
            b = array[i+1];
        }
    }
    cout << a << endl << b <<endl;
}

int main (int argc, char *argv[]) {
    int array[] = {4,15,8,1,19,0,12};
    merge_sort(array,0,size(array)-1); //O(n*logn) 
    solve(array,size(array));    
    return 0;
}
