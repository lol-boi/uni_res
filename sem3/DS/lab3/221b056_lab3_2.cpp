#include <iostream> 
using namespace std;

int search_ele(int arr[], int n, int ele){
    for(int i = 0; i<n; i++){
        if(arr[i] == ele)
            return i;
    }
    return -1;
}

int main(){
    int n = 10;
    int arr[] = {1,4,3,2,4,3,4,1,2,8};  
    cout << "Enter the element to search: ";
    int ele;
    cin >> ele;
    cout << "Returned index value is: ";
    cout<<search_ele(arr, n , ele) << endl;
    
}