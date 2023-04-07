

#include <iostream>
using namespace std;

int nflsat[85];
int cmp_count = 0;
int mov_count = 0;
int n;

void Input() {
	while (true) {
		cout << "masukkan panjang element array : ";
		cin >> n;

		if (n <= 85)
			break;
		else
			cout << "\nmaksimum panjang array adalah 85" << endl;
	}

	cout << "========================" << endl;
	cout << "\nmasukkan element array" << endl;
	cout << "========================" << endl;

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

		while ((nflsat[NS] > pivot) && (NS >= low)) {
			NS--;
			cmp_count++;
		}
	}
	cmp_count++;
	if (i < NS) {

		swap(i, NS);
		mov_count++;
	}
	if (low < NS) {

		swap(low, NS);
		mov_count++;
	}
	Algorithm(low, NS - 1);

	Algorithm(NS + 1, high);
	
}

void Display() {
	cout << "\n====================" << endl;
	cout << "\narray yang terususun" << endl;
	cout << "\n====================" << endl;

	for (int i = 0; i < n; i++) {
		cout << nflsat[i] << " " << endl;
	}
	cout << "\n\njumlah data yang dibandingkan : " << cmp_count << endl;
	cout << "jumlah data yang berpindah : " << mov_count << endl;
}

int main() {
	Input();
	Algorithm(0, n - 1);
	Display();

	return 0;
}