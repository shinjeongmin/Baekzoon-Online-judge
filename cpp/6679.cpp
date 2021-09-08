#include<iostream>
#include<cmath>
using namespace std;

#define endl "\n";

int decimal(int num, int base) {
	int div = base;
	int sum_digits = 0;
	int digits_arr[5] = { 0, };
	for (int p = 4; p >= 0; p--) {
		while (num >= pow(div, p)) 
		{
			num -= (int)pow(div, p);
			digits_arr[p]++;
		}
	}

	for (int i = 0; i < 5; i++) {
		sum_digits += digits_arr[i];
	}

	return sum_digits;
}

int main() {
	for (int i = 1000; i <= 9999; i++) {
		if (decimal(i, 10) == decimal(i, 12) &&
			decimal(i, 10) == decimal(i, 16))
			cout << i << endl;
	}
}