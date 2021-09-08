#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N, M, count{ 0 };

	cin >> N >> M;

	vector<string> str;
	/*결과(듣보잡들)을 담는 벡터*/
	vector<string> result;
	string tmpstr;

	for (int i = 0; i < N + M; i++)
	{
		cin >> tmpstr;
		str.push_back(tmpstr);
	}

	//sort 함수를 이용한 오름차순 정렬, less는 표준 비교 library
	sort(str.begin(), str.end(), less<string>());

	// 모든 문자열을 받고 정렬하면 같은 이름은 붙어있으므로
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == str[i + 1])
		{
			count++;
			result.push_back(str[i]);
		}
	}

	cout << count << "\n";
	for (auto it : result) {
		cout << it << "\n";
	}
}