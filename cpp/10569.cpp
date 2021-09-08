#include <iostream>
using namespace std;

int main() {
	int T, V, E;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> V >> E;
		cout << 2 - (V - E) << "\n";
	}
}