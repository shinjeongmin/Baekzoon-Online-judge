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
int cache[MAX][MAX][10+1]; // ������ 11�� �� �ձ� ����

int BFS() {
	queue<pair<pair<int, int>, int>>q; //y, x, �� �ձ�
	q.push(make_pair(make_pair(0, 0), K)); // ������, �� �ձ� ����
	cache[0][0][K] = 1; // �湮 ó��

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		// �����ϸ�
		if (y == N - 1 && x == M - 1) // �ε��� 0,0���� �����̹Ƿ� ���� -1
			return cache[y][x][block]; // �����ϴ� ĭ�� ����

		for (int i = 0; i < 4; i++) {
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			if (0 <= nextY && nextY < N &&
				0 <= nextX && nextX < M) {
				// ���� �ְ�, ���� 10�� ��� ������ �ʾҴٸ�, �湮���� �ʾҴٸ�
				if (graph[nextY][nextX] == 1 && block > 0 && cache[nextY][nextX][block] == 0) {
					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1; // ���� �հ� �̵�
					q.push(make_pair(make_pair(nextY, nextX), block - 1)); // �̵��� �ڸ��� ť�� �ֱ� (�� �ձ� �Ҹ�)
				}
				// ���� ���� �湮���� �ʾҴ� ���̶��
				else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0) {
					cache[nextY][nextX][block] = cache[y][x][block] + 1; // ���� �ڸ� �湮 ó��
					q.push(make_pair(make_pair(nextY, nextX), block)); // �̵��� �ڸ��� ť�� �ֱ� (�� �ձ� ���δ� ����)
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