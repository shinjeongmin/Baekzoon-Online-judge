#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long result{ 1 };

	for (int i = 1; i <= N; i++) {
		result += (2 * (i + 1) + (i - 1));
	}

	cout << result % 45678;
}