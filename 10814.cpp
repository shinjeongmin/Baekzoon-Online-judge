#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

//***주의*** sort와 stable_sort의 차이점을 모르면 풀 수 없는 문제

bool comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, string>> vec;

	string name;
	int age;
	for (int i = 0; i < N; i++) {	
		pair<int,string> tmp;

		cin >> age;
		cin >> name;
		tmp.first = age;
		tmp.second = name;
		vec.push_back(tmp);
	}

	// sort는 비교하지 않는 값(이름)의 기존 순서를 보장할 수 없음.
	// stable_sort를 이용해야 입력한 순서대로 값(이름)이 보장됨.
	stable_sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
}