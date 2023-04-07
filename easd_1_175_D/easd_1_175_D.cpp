

#include <iostream>
using namespace std;

int nflsat[85];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true) {
		cout << "masukkan panjang element array : ";
		cin >> n;

		if (n <= 85)
			break;
		else
			cout << "\nmaksimum panjang array adalah 85" << endl;
	}

	cout << "---------------------" << endl;
	cout << "\nenter array element" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "). ";
		cin >> nflsat[i];
	}
}

void swap(int x, int y) {
	int temp;
	temp = nflsat[x];
	nflsat[x] = nflsat[y];
	nflsat[y] = temp;
}

void Algorithm(int low, int high) {
	int pivot, i, NS;
	if (low > high)
		return;


	pivot = nflsat[low]; 
	i = low + 1;
	NS = high; 

	while (i <= NS) {

		while ((nflsat[i] <= pivot) && (i <= high)) {
			i++;
			cmp_count++;
		}
		cmp_count++;

		while ((nflsat[j] > pivot) && (j >= low)) {
			NS--;
			cmp_count++;
		}
	}
	cmp_count++;
	if (i < j) {

		swap(i, NS);
		mov_count++;
	}
	
	
}
