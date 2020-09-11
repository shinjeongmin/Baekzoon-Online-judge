#include<iostream>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool number[11] = { false, };
	int Testcase;
	cin >> Testcase;
	for (int t = 0; t < Testcase; t++)
	{
		string s;
		cin >> s;
		for (int i = 0; i < 11; i++)
		{
			number[i] = false;
		}

		int beauty{ 0 };
		for (int i = 0; i < s.length(); i++)
		{
			if (number[s[i] - '0'] == false)
			{
				number[s[i] - '0'] = true;
				beauty++;
			}
		}

		cout << beauty << endl;
	}
}