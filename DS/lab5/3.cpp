#include <iostream>
using namespace std;

int main(){
    int m, n;
    int size = 0;
    cout << "Enter the column and rows length: ";
    cin >> m >> n;
    int sparse[m][n];
    for(int i = 0; i<m; i++){
        cout << "Enter the " << i <<" column: ";
        for(int j = 0 ; j<n; j++){
            cin >> sparse[i][j];
            if(sparse[i][j] != 0) size++;
        }
    }
    int new_matrix[3][size];
    int tmp = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(sparse[i][j] != 0){
                new_matrix[0][tmp] = i;
                new_matrix[1][tmp] = j;
                new_matrix[2][tmp] = sparse[i][j];
                tmp++;   
            }
        }
    }

    for(int i = 0; i<3; i++){
        cout << endl;
        for(int j = 0 ; j<size; j++)
            cout << new_matrix[i][j] << " ";
    }  
}

