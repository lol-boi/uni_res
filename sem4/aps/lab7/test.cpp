#include <iostream>
#include <climits>

using namespace std;
const int MAX_SIZE = 100;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapifyUp(int A[], int n) {
  int i = n;
  while (i > 1 && A[i] > A[i / 2]) {
    swap(&A[i], &A[i / 2]);
    i /= 2;
  }
}

void maxHeapifyDown(int A[], int n, int i) {
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && A[left] > A[largest])
    largest = left;
  if (right <= n && A[right] > A[largest])
    largest = right;

  if (largest != i) {
    swap(&A[i], &A[largest]);
    maxHeapifyDown(A, n, largest);
  }
}

void insert(int A[], int &n, int key) {
  if (n >= MAX_SIZE) {
    cout << "Overflow error: Queue is full\n";
    return;
  }
  n++;
  A[n] = INT_MIN; 
  maxHeapifyUp(A, n);
  A[n] = key;
}


int extractMax(int A[], int &n) {
  if (n == 0) {
    cout << "Underflow error: Queue is empty\n";
    return -1;
  }
  int max = A[1];
  swap(&A[1], &A[n]);
  n--;
  maxHeapifyDown(A, n, 1);
  return max;
}


void increaseKey(int A[], int n, int i, int key) {
  if (i < 1 || i > n) {
    cout << "Invalid index\n";
    return;
  }
  if (key < A[i]) {
    cout << "Error: New key is smaller than current key\n";
    return;
  }
  A[i] = key;
  maxHeapifyUp(A, i);
}


void printQueue(int A[], int n) {
  for (int i = 1; i <= n; i++)
    cout << A[i] << " ";
  cout << endl;
}

int main() {
  
    int A[MAX_SIZE];
  int n = 0;
  insert(A, n, 3);
  insert(A, n, 2);
  insert(A, n, 15);
  insert(A, n, 5);
  insert(A, n, 4);
  insert(A, n, 45);

  cout << "Max-Heap: ";
  printQueue(A, n);
  cout << "Extracted max: " << extractMax(A, n) << endl;
  increaseKey(A, n, 2, 10); 
  cout << "Max-Heap after increase: ";
  printQueue(A, n);
  return 0;
}
