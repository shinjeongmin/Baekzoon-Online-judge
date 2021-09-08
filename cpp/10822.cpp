#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	string s, temp;
	long long result{ 0 };
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') // ,이면
		{
			// 현재 temp의 값 정수형으로 넣고 초기화
			result += stoll(temp);
			temp = "0";
		}
		else
		{
			// temp에 숫자를 숫서대로 넣기
			temp += s[i];
		}
	}
	result += stoll(temp);

	cout << result;
}