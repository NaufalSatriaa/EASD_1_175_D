

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