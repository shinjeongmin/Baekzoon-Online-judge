#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	float arr[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
	int number[5];
	float sum{ 0 };
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		sum = 0;
		for (int i = 0; i < 5; i++) {
			cin >> number[i];
			sum += number[i] * arr[i];
		}
		cout << fixed << setprecision(2) << '$' << sum << "\n";
	}
}