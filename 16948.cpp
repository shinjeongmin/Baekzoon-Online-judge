#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 200;
const int INF = 999999999;

typedef struct {
	int x, y;
}Div;

Div moveDiv[] = { {-2,-1}, {-2,1}, {0,-2}, {0,2}, {2,-1}, {2,1} };
int N;
pair<int, int> start, dest;
bool check[MAX][MAX];
int cache[MAX][MAX];

void initialize() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cache[i][j] = INF;
		}
	}
}

int BFS(int x,int y) {
	// ĳ�� �ʱ�ȭ
	initialize();

	// ť�� ���� �� ó�� ��ġ �ֱ�
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));

	// ó����ġ�� �̵�Ƚ���� 0
	cache[x][y] = 0;

	while (!q.empty()) {
		// ť�� front�� ���� ��ġ�� ����
		pair<int, int> curPos = q.front();
		q.pop();

		// ������ġ�� �������� ��ġ�ϸ� ���� ��ġ�� ĳ�� ��ȯ
		if (curPos.first == dest.first &&
			curPos.second == dest.second) {
			return cache[curPos.first][curPos.second];
		}

		for (int i = 0; i < 6; i++) {
			// ������ġ ����
			int nextX = curPos.first + moveDiv[i].x;
			int nextY = curPos.second + moveDiv[i].y;

			// ������ġ�� ���� �� Ž������ Ȯ��
			if (0 <= nextX && nextX < N &&
				0 <= nextY && nextY < N && !check[nextX][nextY]) {
				// ������ġ ť�� �ֱ�
				q.push(make_pair(nextX, nextY));

				// ������ġ Ž�� ����
				check[nextX][nextY] = true;

				// ������ġ�� �̵�Ƚ���� �������� ���Ͽ� �缳��
				cache[nextX][nextY] = min(cache[nextX][nextY], cache[curPos.first][curPos.second] + 1);
			}
		}
	}
	// �̵��� �� ���� ���
	return -1;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	memset(check, false, sizeof(check));

	cin >> N >> start.first >> start.second
		>> dest.first >> dest.second;
	cout << BFS(start.first, start.second) << "\n";

}
//���ѽð� 3:20