// 1. Algoritma mempermudah dalam memecahkan segala permasalahan yang berkaitan dengan suatu program dan tidak dapat diselesaikan dengan mudah.
// 2. Statis dan dinamis.
// 3. Ada output, efektifitas dan efisiensi, jumlah langkahnya berhingga, (semi algoritma) berakhir dan terstruktur.
// 4. Algoritma Quicksort. Kelebihan dari algoritma ini adalah kinerjanya yang sangat cepat dibanding algoritma pengurutan data lainnya, bahkan untuk data yang berukuran besar. 
//Quicksort memanfaatkan metode divide and conquer yang memungkinkan untuk mengurangi kompleksitas waktu secara drastis. 
//Oleh karena itu, quicksort lebih efisien dan mudah diimplementasikan untuk data berukuran besar.
// 5. Quadratic : Bubblesort, Selectionsort, Insertionsort, dan Shellsort.
//Loglinear : Quicksort dan Mergesort

// 6. Membuat program :
#include <iostream>
using namespace std;

int nflsat[95];
int cmp_count = 0;
int mov_count = 0;
int n;

void Input() {
	while (true) {
		cout << "masukkan panjang element array : ";
		cin >> n;

		if (n <= 95)
			break;
		else
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
			cout << "\nMAKSIMUM PANJANG ARRAY ADALAH 95";
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << endl;
	}

	cout << "========================" << endl;
	cout << "\nMasukkan element array" << endl;
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
	cout << "\nArray yang terususun" << endl;
	cout << "\n====================" << endl;

	for (int i = 0; i < n; i++) {
		cout << nflsat[i] << " " << endl;
	}
	cout << "\n\nJumlah data yang dibandingkan : " << cmp_count << endl;
	cout << "Jumlah data yang berpindah : " << mov_count << endl;
}

int main() {
	Input();
	Algorithm(0, n - 1);
	Display();

	return 0;
}