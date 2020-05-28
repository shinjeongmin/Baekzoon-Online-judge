#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <string>
using namespace std;

bool comp(pair<string,int> a, pair<string,int> b) {
		return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<pair<string, int>> guide;
	vector<pair<string, int>> guide2;

	for (int i = 0; i < N; i++)
	{
		pair<string,int> temp;
		cin >> temp.first;
		temp.second = i + 1;

		guide.push_back(temp);
	}

	vector<string> quiz;
	vector<pair<string,int>>::iterator iter;

	// 벡터 복사
	guide2 = guide;
	// 정렬
	sort(guide.begin(), guide.end(), less<pair<string, int>>());
	sort(guide2.begin(), guide2.end(), comp);

	for (int i = 0; i < M; i++)
	{
		pair<string, int> tempsearch;
		string temp;
		cin >> temp;
		if ('0' <= temp[0]
			&& temp[0] <= '9')
		{// 숫자이면
			int num = stoi(temp);

			tempsearch.first = "";
			tempsearch.second = num;

			iter = lower_bound(guide2.begin(), guide2.end(), tempsearch, comp);

			cout << (*iter).first << "\n";
		}
		else 
		{// 이름일 경우
			tempsearch.first = temp;

			iter = lower_bound(guide.begin(), guide.end(), tempsearch);

			cout << (*iter).second << "\n";
		}
	}
}