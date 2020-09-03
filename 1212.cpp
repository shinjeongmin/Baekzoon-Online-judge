#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
	string oct, bin = "", result;
	cin >> oct;
	for (int i = 0; i < oct.length(); i++) {
		int step;
		step = oct[i] - '0';

		for (int j = 2; j >= 0; j--) {
			if (step >= pow(2, j))
			{
				step -= pow(2, j);
				bin += '1';
			}
			else
				bin += '0';
		}
	}

	if (oct == "0")
	{
		cout << 0;
		return 0;
	}


	// 앞에 0 없애기
	bool firstZ = false;
	for (int i = 0; i < bin.length(); i++)
	{
		if (firstZ)
		{
			result += bin[i];
		}

		if (bin[i] == '1' && !firstZ)
		{
			result += bin[i];
			firstZ = true;
		}
	}

	cout << result;
}