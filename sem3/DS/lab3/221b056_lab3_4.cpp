#include <iostream> 
using namespace std;

int check_dup(int arr[], int n){
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }

    return 0;
}



int main(){
    int arr[] = {12,423,423,11,89,23};
    int n = 6;
    if(check_dup(arr, n) == 1){
        cout << "Duplicates found!" << endl;
    }
    else cout << "No Duplicates found!";
}