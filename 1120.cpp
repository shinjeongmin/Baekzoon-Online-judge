#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int INF = 987654321;

string s1, s2;
int result;

void minDifference(void) {
	//greedy ����
	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < s1.length(); j++) { //s1�� ó������ s2�� �ϳ��� ��
			if (s1[j] != s2[j + i]) //���� ���ڿ��� �󸶳� �з��ִ°� ĭ���� ��
				cnt++;
		}
		result = min(result, cnt); //���� result���� ������ ����
	}
}

int main() {
	cin >> s1 >> s2;

	result = INF;
	minDifference();

	cout << result << "\n";
}
