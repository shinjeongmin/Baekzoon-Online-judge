#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;

typedef struct {
	int x, y;
}Dir;

int T, I;
pair<int, int> start, dest;
bool check[300][300];
int cache[300][300];
Dir moveDir[8] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

void init() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			cache[i][j] = INF;
		}
	}
}

int BFS(int firX, int firY) {
	init();

	queue<pair<int,int>> Q;

	// ù��° ĭ�� ť�� �߰�
	Q.push(make_pair(firX, firY));
	cache[firX][firY] = 0;

	while (!Q.empty()) {
		//ť���� front ���� ���� ��ġ�� ����
		pair<int, int> curPos = Q.front();
		Q.pop();

		//����ĭ�� �������� ��� ������������ �̵����� ��ȯ
		if (curPos.first == dest.first &&
			curPos.second == dest.second)
			return cache[curPos.first][curPos.second];

		// �̵��� �� �ִ� �� 8���� �ݺ��� ����
		for (int i = 0; i < 8; i++) {
			// ����ĭ�� ������ ����.
			int nextX = curPos.first + moveDir[i].x;
			int nextY = curPos.second + moveDir[i].y;

			// ���� ����ĭ�� ������ ����� �ʰ� ������ ���� ��� ť�� �߰�
			if (0 <= nextX && nextX < I &&
				0 <= nextY && nextY < I && !check[nextX][nextY]) {
				Q.push(make_pair(nextX, nextY));
				// ����ĭ�� Ž���� ������ üũ
				check[nextX][nextY] = true;
				// �ּ� �̵��� ȸ���� �缳�� (�������� ����ĭ�϶��� �� ��)
				cache[nextX][nextY] = min(cache[nextX][nextY], cache[curPos.first][curPos.second] + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		memset(check, false, sizeof(check));

		cin >> I >> start.first >> start.second >> dest.first >> dest.second;
		cout << BFS(start.first, start.second) << "\n";
	}
	return 0;
}

//���ѽð� 10:20