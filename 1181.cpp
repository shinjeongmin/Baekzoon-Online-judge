#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() < b.size()) // 앞의 단어가 더 길면 교체
		return true; 
	else if(a.size() == b.size())
	{
		if (a < b) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<string> vec;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	stable_sort(vec.begin(), vec.end(),cmp);

	// set을 이용하지 않고 벡터의 i + 1인덱스로 중복 출력을 거름
	for (int i = 0; i < N; i++) {
		if (i != N - 1)
		{
			if (vec[i + 1] == vec[i])
			{
				continue;
			}
			else
				cout << vec[i] << "\n";
		}
		else
			cout << vec[i] << "\n";
	}
}