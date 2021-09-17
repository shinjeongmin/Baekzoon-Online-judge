#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[2001];
int arr[2001][2001] = { 0, };
int check[2001] = { 0, };

void init() {
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			arr[i][j] = 0;
		}
		arr[i][i] = 0;
		graph[i].clear();
	}
}

void initCheck() {
	for (int i = 0; i < 2001; i++) {
		check[i] = 0;
	}
}

void dfs(int root, int idx, int N, int totalPath) {
	arr[root][idx] = totalPath;
	check[idx] = 1;

	for (int i : graph[idx]) {
		if (check[i] == 0) {
			dfs(root, i, N, totalPath + arr[idx][i]);
		}
	}
}

int main() { // cycle이 생기지 않는 그래프
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		int N;
		cin >> N;
		for (int i = 0; i < N-1; i++) {
			int n, v, d;
			cin >> n >> v >> d;
			arr[n][v] = d;
			arr[v][n] = d;
			graph[n].push_back(v);
			graph[v].push_back(n);
		}

		// 간선이 1개인 노드 모두에 대해 탐색
		for (int i = 1; i <= N; i++) {
			if (graph[i].size() == 1)
			{
				initCheck();
				dfs(i, i, N, 0);
			}
		}

		// 출력
		int max = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (max < arr[i][j]) {
					max = arr[i][j];
				}
			}
		}
		cout << max << "\n";
	}
}
/*
2
5
1 2 5
2 3 1
3 4 2
4 5 3
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
*/