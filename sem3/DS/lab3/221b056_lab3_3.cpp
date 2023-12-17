#include <iostream> 
using namespace std;

int search_ele(int arr[], int n, int ele){
    for(int i = 0; i<n; i++){
        if(arr[i] == ele)
            return i;
    }
    cout <<"Error: element not found";
    return -1;
}

void del_ele(int arr[], int n, int index){
    for(int i = index; i<n-1; i++){
        arr[i] = arr[i+1];
    } 

    for(int i = 0 ; i<n-1; i++){
        cout <<" " << arr[i];
    }
} 

int main(){
    int n = 10;
    int arr[] = {1,4,3,2,4,3,4,1,2,8};  
    cout << "Enter the element to search: ";
    int ele;
    cin >> ele;
    cout << "Returned index value is: ";
    int index = search_ele(arr,n,ele);
    cout << index << endl;
    if(index == -1){
        return 0; 
    }
    else{
        del_ele(arr, n,index);         
    }
    
}