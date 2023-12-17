#include <iostream>
using namespace std;


int main(){
    int n;
    int arr[n][n];
    int count = 0;
    cout << "Enter the size: ";
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << " Enter the row: " ;
        for(int j = 0; j<n ; j++){
            cin >> arr[i][j]; 
        }
    }
    count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<count; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl; 
        count++;
    }
}