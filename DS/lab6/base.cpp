#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* Rdm(int n) {
    int* randomArray = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        randomArray[i] = std::rand() % 100;
    }
    return randomArray;
}

int main() {
    int n;
	cout << "Enter the size of the array: ";
	cin >> n;
   	int* randomNumbers = Rdm(n);
	cout << "Random Numbers: ";
	for (int i = 0; i < n; i++) {
		cout << randomNumbers[i] << " ";
	}
	cout << endl;
	delete[] randomNumbers;

	return 0;
}

