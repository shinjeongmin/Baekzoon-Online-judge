#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	string s, temp;
	long long result{ 0 };
	cin >> s;

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