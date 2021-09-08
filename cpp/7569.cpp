#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100;

struct triple {
	triple(int x, int y, int z)
		:x(x), y(y), z(z)
	{ }
	int x, y, z;
};

triple moveDir[6] = { {1,0,0}, {-1,0,0}, {0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

int M, N, H;
int tomato[MAX][MAX][MAX];
queue<triple>q;
int noTomato;

// �丶�䰡 ���� �;����� Ȯ��
bool allRipe() {
	int possible = M * N * H - noTomato; // ��ü �丶�䰳�� - ���� �丶�� ����
	int cnt = 0; // ���� ���� �丶�� ����

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[k][j][i] == 1)
					cnt++;
			}
		}
	}
	return possible == cnt; // ���� �� �ִ� �丶�䰡 ��� �;��°�?
}

int BFS() {
	int day = 0;

	// ó������ ���� �� �ִ� �丶�䰡 ���� ���
	while (q.empty()) {
		return -1;
	}
	
	while (!q.empty()) {
		int currentSize = q.size(); // ť�� ����ִ� ������ŭ �ݺ��� (�Ϸ����� ��� �丶�䰡 ������ ����)
		
		for (int i = 0; i < currentSize; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;

			for (int i = 0; i < 6; i++) {
				int nextX = x + moveDir[i].x;
				int nextY = y + moveDir[i].y;
				int nextZ = z + moveDir[i].z;

				// ���� �丶�䰡 ���� �ȿ� �ְ� �� �;��� ��쿡��
				if (0 <= nextX && nextX < M &&
					0 <= nextY && nextY < N &&
					0 <= nextZ && nextZ < H &&
					tomato[nextX][nextY][nextZ] == 0) {
					tomato[nextX][nextY][nextZ] = 1; // �湮 üũ
					q.push(triple(nextX, nextY, nextZ)); // ���� �丶�� ��ġ ť�� ����
				}
			}
			q.pop();
			
			// ���� �� �ִ� �丶�並 ���� ������, ���� �;��� ���
			if (q.size() == 0 && allRipe())
				return day;
			// ���� �� �ִ� �丶��� ���� ��������, �� ���� �丶�䰡 ���� ���
			/*else if (q.size() == 0 && !allRipe())
				return -1;*/
		}
		day++;
	}
	return -1;
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> tomato[k][j][i];
				if (tomato[k][j][i] == 1)
					q.push(triple(k, j, i)); // ���� �丶��� ť�� �ִ´�.
				if (tomato[k][j][i] == -1)
					noTomato++; // �丶�並 ���� �� ���� ĭ
			}

	if (q.size() == M * N * H - noTomato)
	{
		cout << 0 << endl; // ��� �丶�� �� �;��� ���
	}
	else {
		int result = BFS();
		cout << result << endl;
	}
}
// ���ѽð� 9:20