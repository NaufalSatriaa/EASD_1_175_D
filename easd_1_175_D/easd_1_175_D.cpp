

#include <iostream>
using namespace std;

int nflsat[85];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true) {
		cout << "masukkan panjang element array" << endl;
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nmaksimum panjang array adalah 20" << endl;
	}

}