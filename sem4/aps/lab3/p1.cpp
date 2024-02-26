#include <iostream>
using namespace std;

void displayArray(int arr[], int size){
   for(int i = 0; i<size; i++){
       cout << arr[i] << " ";
   } 
   cout << endl;

}
void merge(int array[], int start, int mid, int end){
    int arrayOneSize = mid - start+1;
    int arrayTwoSize = end - mid;

    int leftArray[arrayOneSize];
    int rightArray[arrayTwoSize];
   
    for(int i = 0; i<arrayOneSize; i++)
        leftArray[i] = array[start+i]; 
    //displayArray(array,arrayOneSize)
    for(int i = 0; i<arrayTwoSize; i++)
       rightArray[i] = array[mid+1+i];
    //displayArray(array,arrayTwoSize)
    int tmpOne =0;int tmpTwo = 0; int tmp = start;
    while(tmpOne <= arrayOneSize && tmpTwo <= arrayTwoSize){
        if(leftArray[tmpOne] <= rightArray[tmpTwo]){
            array[tmp++] = leftArray[tmpOne++]; 
        }
        else{
            array[tmp++] = rightArray[tmpTwo++];
        }
    }
    
    while(tmpOne<= arrayOneSize){
        array[tmp++] = leftArray[tmpOne++]; 
    }
    while(tmpTwo <= arrayTwoSize){
        array[tmp++] = rightArray[tmpTwo++]; 
    }
       

}


void mergesort(int array[], int start, int end){
    if(start < end){
        int mid = start+(end-start)/2;
        mergesort(array, start,mid);
        mergesort(array, mid+1,end);
        merge(array,start, mid, end);
    } 
    return; 
}





int main(){
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int randArray[size];
    for(int i=0;i<size;i++)
      randArray[i]=rand()%100;
    cout << "Array before sorting: " << endl;
    displayArray(randArray,size);
    mergesort(randArray,0,size-1);
    displayArray(randArray,size);
}
