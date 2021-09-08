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
	queue<pair<tuple<int, int, int>, pair<int, string>>> Q; // x,y, 이동횟수, 벽 부분 수, 아침저녁
	Q.push(make_pair(make_tuple(a, b, 1), make_pair(0, "Morning")));
	Visit[a][b][0] = true; // 첫칸 방문처리

	while (Q.empty() == 0)
	{
		int x = get<0>(Q.front().first);
		int y = get<1>(Q.front().first);
		int Cnt = get<2>(Q.front().first);
		int K_Num = Q.front().second.first;
		string Day = Q.front().second.second;
		Q.pop();

		// 일치하면 바로 Cnt 출력
		if (x == N - 1 && y == M - 1)
		{
			cout << Cnt << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // 다음 x좌표
			int ny = y + dy[i]; // 다음 y좌표

			// 좌표 범위 확인
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				// 벽이 없을 때
				if (MAP[nx][ny] == 0) 
				{
					// 방문하지 않았다면
					if (Visit[nx][ny][K_Num] == false)
					{
						Visit[nx][ny][K_Num] = true;
						if (Day == "Morning") // 아침이면 이동후 저녁
							Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num, "Night")));
						else  // 저녁이면 이동 후 아침
							Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num, "Morning")));
					}
				}
				// 벽이 있을 때
				else if (MAP[nx][ny] == 1)
				{
					// 부순 벽의 개수가 총 벽의 개수를 넘어가지 않는다면
					if (K_Num < K)
					{
						// 방문하지 않았다면
						if (Visit[nx][ny][K_Num + 1] == false)
						{
							if (Day == "Morning")
							{ // 아침이면 부수고 이동
								Visit[nx][ny][K_Num + 1] = true;
								Q.push(make_pair(make_tuple(nx, ny, Cnt + 1), make_pair(K_Num + 1, "Night")));
							}
							else
							{ // 저녁이면 현재 칸을 반복
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