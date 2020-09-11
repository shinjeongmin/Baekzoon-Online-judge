#include<iostream>
#include<string>
#define endl '\n'
using namespace std;

int main() {
	string key,str;
	getline(cin, str);
	cin >>  key;
	for (int i = 0; i < str.length(); i++) {
		int keyIndex = i % key.length();
		if (str[i] == ' ')
			cout << ' ';
		else
		{
			char pwd = str[i] - key[keyIndex] + 'a' - 1;
			if (str[i] - key[keyIndex] <= 0)
				pwd += 26;
			cout << pwd;
		}
	}
}