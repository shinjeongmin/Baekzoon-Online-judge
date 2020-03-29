#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> vec;
	string input;
	int len;

	cin >> input;
	len = input.size();
	for (int i = 0; i < len; i++) {
		string temp;
		for (int j = i; j < len; j++)
		{
			temp += input[j];
		}
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}