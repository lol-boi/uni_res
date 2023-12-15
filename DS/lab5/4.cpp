#include <iostream>
using namespace std;

int main(){
    cout << "Enter the size of the array: ";
    int s;
    cin >> s;
    cout << "Enter the array: ";
    int arr[s];
    int key = 0;
    for(int i = 0; i<s; i++){
        cin >> arr[i];
        if(key < arr[i])
            key = arr[i];
    }
    int hash[key+1]= {0};
    for(int i = 0; i<s; i++){
        hash[arr[i]]++;
    }
    int tmp = hash[0];
    int res = 0; 
    for(int i = 0; i<key+1; i++){
       if(hash[i] > tmp){
           tmp = hash[i];
           res = i;
       } 
    }
    cout << endl << res << endl;
    
}