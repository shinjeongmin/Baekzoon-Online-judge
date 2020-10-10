#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s;
	int input;

	cin >> input;
	if (input == 0)
	{
		s = "0";
	}
	else if(input > 0)
	{
		while (input > 1) {
			if (input % 2 == 1) {
				s += '1';
			}
			else
				s += '0';

			input /= 2;
		}
		s += '1';
	}
	else
	{
		cout << 32;
		return 0;
	}
	reverse(s.begin(), s.end()); 
	//cout << s << endl;
	cout << s.length();
}