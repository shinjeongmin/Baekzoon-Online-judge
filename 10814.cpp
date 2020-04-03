#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

//***����*** sort�� stable_sort�� �������� �𸣸� Ǯ �� ���� ����

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

	// sort�� ������ �ʴ� ��(�̸�)�� ���� ������ ������ �� ����.
	// stable_sort�� �̿��ؾ� �Է��� ������� ��(�̸�)�� �����.
	stable_sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
}