#include <iostream>
using namespace std;

int main() {
	bool attend[30] = { false };
	int n;

	for (int i = 0; i < 28; i++) {
		cin >> n;
		attend[n - 1] = true;
	}

	for (int i = 0; i < 30; i++) {
		if (attend[i] == false)
			cout << i + 1 << "\n";
	}
}