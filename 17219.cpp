#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<pair<string,string>> site;

	for (int i = 0; i < N; i++)
	{
		pair<string, string> temp;
		cin >> temp.first >> temp.second;
		site.push_back(temp);
	}

	sort(site.begin(), site.end());

	vector<pair<string,string>>::iterator iter;

	int idx;
	for (int i = 0; i < M; i++)
	{
		pair<string,string> temp;
		cin >> temp.first;

		iter = lower_bound(site.begin(), site.end(), temp);
		idx = distance(site.begin(), iter);
		cout << site[idx].second << "\n";
	}
}