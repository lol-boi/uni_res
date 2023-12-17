#include <iostream> 
using namespace std;

void add_ele(int arr[], int n, int ele, int index){
    int new_arr[n+1];
    n+=1;
    for(int i =0;i< 10; i++){
        new_arr[i] = arr[i];   
    }
    for(int i = n-1; i>index; i--){
        new_arr[i] = new_arr[i-1];
    } 
    new_arr[index] == ele;
    for(int i = 0 ; i<n; i++) cout <<" " << new_arr[i];
}

int main(){
    int n = 10;
    int arr[] = {1,4,3,2,4,3,4,1,2,8};  
    cout << "Enter the element and the index: ";
    int ele, index;
    cin >> ele >> index;
    cout << "The array is: "; 
    for(int i = 0; i<10; i++){ 
        cout << arr[i] << " ";
    }
    add_ele(arr, n , ele, index);

}