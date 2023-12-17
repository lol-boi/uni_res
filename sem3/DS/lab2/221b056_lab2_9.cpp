#include <iostream>
using namespace std;

int  find_max(int arr[], int n){  
    int maxcountnum;
    int maxcount = 0;
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }     
        if(count > maxcount){
            maxcount = count;
            maxcountnum = arr[i];
        } 
    }
    return maxcountnum;
}

int main(){
    int n = 12;
    int arr[]= {3,2,23,1,2,34,2,4,1,3,1,1};
    cout << find_max(arr, n); 
}
