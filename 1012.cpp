#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <array>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

int M, N, K;
bool check[50][50];
bool grid[50][50];
int cnt;
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		if (0 <= x + dx[i] && x + dx[i] < M &&
			0 <= y + dy[i] && y + dy[i] < N)
			if (!check[x + dx[i]][y + dy[i]] &&
				grid[x + dx[i]][y + dy[i]])
			{
				dfs(x + dx[i], y + dy[i]);
			}
	}
}

int main() 
{
	ios_base::sync_with_stdio;
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		
		//check√ ±‚»≠
		for (int i = 0; i < N; i++)
			fill_n(check[i], M, false);
		for (int i = 0; i < N; i++)
			fill_n(grid[i], M, false);
		cnt = 0;

		for (int k = 0; k < K; k++)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = true;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!check[i][j] &&
					grid[i][j])
				{
					check[i][j] = true;
					cnt++;
					dfs(i,j);
				}
			}
		}

		cout << cnt << "\n";
	}
}
/*
*/