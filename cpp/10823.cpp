#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	string s, temp, str;
	long long result{ 0 };
	for (int j = 0; j < 10000; j++) {
		getline(cin, str);

		s += str;
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') // ,�̸�
		{
			// ���� temp�� �� ���������� �ְ� �ʱ�ȭ
			result += stoll(temp);
			temp = "0";
		}
		else
		{
			// temp�� ���ڸ� ������� �ֱ�
			temp += s[i];
		}
	}
	result += stoll(temp);

	cout << result;
}