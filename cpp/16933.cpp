#include<iostream>
#include<queue>
#include<string>
#include<tuple>

#define MAX 1000
#define INF 987654321
using namespace std;

int N, M, K;
int MAP[MAX][MAX];
bool Visit[MAX][MAX][11];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) 
	{
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++) {
			MAP[i][j] = Inp[j] - '0';
		}
	}
}

void BFS(int a, int b) {
	queue<pair<tuple<int, int, int>, pair<int, string>>> Q; // x,y, �̵�Ƚ��, �� �κ� ��, ��ħ����
	Q.push(make_pair(make_tuple(a, b, 1), make_pair(0, "Morning")));
	Visit[a][b][0] = true; // ùĭ �湮ó��

	while (Q.empty() == 0)
	{
		int x = get<0>(Q.front().first);
		int y = get<1>(Q.front().first);
		int Cnt = get<2>(Q.front().first);
		int K_Num = Q.front().second.first;
		string Day = Q.front().second.second;
		Q.pop();

		// ��ġ�ϸ� �ٷ� Cnt ���
		if (x == N - 1 && y == M - 1)
		{
			cout << Cnt << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // ���� x��ǥ
			int ny = y + dy[i]; // ���� y��ǥ

			// ��ǥ ���� Ȯ��
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				// ���� ���� ��
				if (MAP[nx][ny] == 0) 
				{
					// �湮���� �ʾҴٸ�
					if (Visit[nx][ny][K_Num] == false)
					{
						Visit[nx][ny][K_Num] = true;
						if (Day == "Morning") // ��ħ�̸� �̵��� ����
							Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num, "Night")));
						else  // �����̸� �̵� �� ��ħ
							Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num, "Morning")));
					}
				}
				// ���� ���� ��
				else if (MAP[nx][ny] == 1)
				{
					// �μ� ���� ������ �� ���� ������ �Ѿ�� �ʴ´ٸ�
					if (K_Num < K)
					{
						// �湮���� �ʾҴٸ�
						if (Visit[nx][ny][K_Num + 1] == false)
						{
							if (Day == "Morning")
							{ // ��ħ�̸� �μ��� �̵�
								Visit[nx][ny][K_Num + 1] = true;
								Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num + 1, "Night")));
							}
							else
							{ // �����̸� ���� ĭ�� �ݺ�
								Q.push(make_pair(make_tuple(x, y, Cnt + 1), make_pair(K_Num, "Morning")));
							}
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return;
}

void Solution()
{
	BFS(0, 0);
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	Solve();

	return 0;
}