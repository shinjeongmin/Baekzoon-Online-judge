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
	//Ž��
	check[i][j] = true;

	pair<int, int> temp(i, j);
	Q.push(temp);

	// ť�� �� ������ Ž��
	while (!Q.empty()) {
		pair<int, int> F = Q.front();
		Q.pop();

		int x = F.first;
		int y = F.second;

		for (int k = 0; k < 4; k++) {
			// �����¿� �� ������ �ʰ����� �ʰ�, Ž������ ���� ���� ť�� ����.
			if (maze[x + dx[k]][y + dy[k]] &&
				!check[x + dx[k]][y + dy[k]] &&
				0 < x + dx[k] && x + dx[k] <= N &&
				0 < y + dy[k] && y + dy[k] <= M) {

				// ����ġ 1 ����
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

// ���ѽð� 5:20