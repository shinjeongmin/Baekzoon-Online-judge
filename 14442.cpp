#include<iostream>
#include<string>
#include <queue>
using namespace std;

const int MAX = 1000;

typedef struct {
	int y, x;
}Dir;

Dir moveDir[4] = { {1,0},{-1,0},{0,1}, {0,-1} };

int N, M, K;
int graph[MAX][MAX];
int cache[MAX][MAX][10+1]; // 마지막 11은 벽 뚫기 여부

int BFS() {
	queue<pair<pair<int, int>, int>>q; //y, x, 벽 뚫기
	q.push(make_pair(make_pair(0, 0), K)); // 시작점, 벽 뚫기 가능
	cache[0][0][K] = 1; // 방문 처리

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		// 도착하면
		if (y == N - 1 && x == M - 1) // 인덱스 0,0부터 시작이므로 각각 -1
			return cache[y][x][block]; // 시작하는 칸도 포함

		for (int i = 0; i < 4; i++) {
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			if (0 <= nextY && nextY < N &&
				0 <= nextX && nextX < M) {
				// 벽이 있고, 벽을 10번 모두 뚫지는 않았다면, 방문하지 않았다면
				if (graph[nextY][nextX] == 1 && block > 0 && cache[nextY][nextX][block] == 0) {
					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1; // 벽을 뚫고 이동
					q.push(make_pair(make_pair(nextY, nextX), block - 1)); // 이동한 자리를 큐에 넣기 (벽 뚫기 소모)
				}
				// 벽이 없고 방문하지 않았던 곳이라면
				else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0) {
					cache[nextY][nextX][block] = cache[y][x][block] + 1; // 다음 자리 방문 처리
					q.push(make_pair(make_pair(nextY, nextX), block)); // 이동한 자리를 큐에 넣기 (벽 뚫기 여부는 유지)
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++)
			graph[i][j] = temp[j] - '0';
	}

	cout << BFS() << "\n";
	return 0;
}