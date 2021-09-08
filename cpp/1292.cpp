#include<iostream>
#define endl '\n'
using namespace std;

int indexNumer(int n) {
	int sum = 0, i;
	for (i = 1; i <= n; i++)
	{
		sum += i;
		if (n <= sum)
		{
			break;
		}
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int min, max, result{ 0 };
	cin >> min >> max;
	for (int i = min; i <= max; i++) {
		result += indexNumer(i);
	}
	cout << result << endl;
}