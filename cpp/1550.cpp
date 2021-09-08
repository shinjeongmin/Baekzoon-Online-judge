#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	string hexa;
	int result{ 0 };
	cin >> hexa;

	reverse(hexa.begin(), hexa.end());
	for (int i = 0; i < hexa.length(); i++) {
		int temp;
		if ('A' <= hexa[i] && hexa[i] <= 'F')
		{
			temp = hexa[i] - 'A' + 10;
			result += temp * pow(16, i);
		}
		else
		{
			temp = hexa[i] - '0';
			result += temp * pow(16, i);
		}
	}
	cout << result << endl;
}