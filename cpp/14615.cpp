#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int N, M, T;
vector<int> adj[2][100000 + 1];
bool Check[2][100000 + 1];

void DFS(int idx, int node) {
	Check[idx][node] = true;

	for (auto it : adj[idx][node]) {
		if (Check[idx][it])
			continue;
		else
			DFS(idx, it);
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int n, m;
		cin >> n >> m;
		adj[0][n].push_back(m); // 정방향 입력
		adj[1][m].push_back(n); // 역방향 입력
	}

	DFS(0, 1);
	DFS(1, N);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int C;
		cin >> C;
		if (Check[0][C] && Check[1][C]) {
			cout << "Defend the CTP\n";
		}
		else {
			cout << "Destroyed the CTP\n";
		}
	}
}