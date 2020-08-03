#include<iostream>
#include <queue>
#include<utility>
#include<algorithm>
using namespace std;

bool maze[101][101];
bool check[101][101];
int mazedistance[101][101];
int N, M;
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
queue<pair<int, int>> Q;

void BFS(int i, int j) {
	//탐색
	check[i][j] = true;

	pair<int, int> temp(i, j);
	Q.push(temp);

	// 큐가 빌 때까지 탐색
	while (!Q.empty()) {
		pair<int, int> F = Q.front();
		Q.pop();

		int x = F.first;
		int y = F.second;

		for (int k = 0; k < 4; k++) {
			// 상하좌우 중 범위를 초과하지 않고, 탐색하지 않은 곳을 큐에 저장.
			if (maze[x + dx[k]][y + dy[k]] &&
				!check[x + dx[k]][y + dy[k]] &&
				0 < x + dx[k] && x + dx[k] <= N &&
				0 < y + dy[k] && y + dy[k] <= M) {

				// 가중치 1 증가
				mazedistance[x + dx[k]][y + dy[k]] = mazedistance[x][y] + 1;

				check[x + dx[k]][y + dy[k]] = true;
				Q.push(pair<int, int>(x + dx[k], y + dy[k]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char temp;
			cin >> temp;

			if (temp == '1')
				maze[i][j] = true;
			else
				maze[i][j] = false;
		}
	}

	mazedistance[1][1] = 1;
	BFS(1, 1);

	cout << mazedistance[N][M] << "\n";
}

// 제한시간 5:20