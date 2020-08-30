#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int INF = 987654321;

string s1, s2;
int result;

void minDifference(void) {
	//greedy 접근
	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < s1.length(); j++) { //s1의 처음부터 s2와 하나씩 비교
			if (s1[j] != s2[j + i]) //같은 문자열이 얼마나 밀려있는가 칸수를 셈
				cnt++;
		}
		result = min(result, cnt); //현재 result보다 작으면 대입
	}
}

int main() {
	cin >> s1 >> s2;

	result = INF;
	minDifference();

	cout << result << "\n";
}
