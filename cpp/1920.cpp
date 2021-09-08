#include<iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	set<int> s;
	set<int>::iterator iter;
	vector<int> v;

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {

		int temp;
		cin >> temp;
		if (s.find(temp) != s.end())
			v.push_back(1);
		else
			v.push_back(0);
	}

	for (int i = 0; i < M; i++) {
		cout << v[i] << "\n";
	}
}