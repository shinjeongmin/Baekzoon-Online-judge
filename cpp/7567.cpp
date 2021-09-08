#include<iostream>
using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int height{ 10 };
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			height += 5;
		}
		else
		{
			height += 10;
		}
	}
	cout << height << endl;
}