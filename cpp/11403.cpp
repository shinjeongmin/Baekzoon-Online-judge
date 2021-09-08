#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

vector<int>vec;
vector<vector<int>> directgraph;
bool check[101][101];

void dfs(int i,int n) {
	for (int k = 0; k < directgraph[n].size(); k++)
	{
		if (!check[i][directgraph[n][k]])
		{
			check[i][directgraph[n][k]] = true;
			dfs(i, directgraph[n][k]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N;
	cin >> N;

	directgraph.assign(N + 1, vec);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			bool temp;
			cin >> temp;
			if(temp)
				directgraph[i].push_back(j);
		}
	}

	// Â÷·Ê´ë·Î Å½»ö
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}

	// Ãâ·Â
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}
}