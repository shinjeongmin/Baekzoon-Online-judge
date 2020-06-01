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

int T, H, W;
bool check[100 + 1][100 + 1]; // grid check
char grid[100 + 1][100 + 1]; // grid
int cnt{ 0 };
const int dy[] = { -1, 1, 0 , 0 }, dx[] = { 0, 0, -1, 1 };

// 양(#) 무리를 탐색하여 모두 check처리하는 함수
void searchSheepBunch(int y, int x) {
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		if (!check[y + dy[i]][x + dx[i]]
			&& grid[y + dy[i]][x + dx[i]] == '#')
		{
			searchSheepBunch(y + dy[i], x + dx[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> H >> W;

		// 초기화
		for(int i = 1; i <= H; i++)
			fill_n(check[i], (W + 1), false);
		/*for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				check[i][j] = false;*/
		cnt = 0;
 
		// 입력
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				char c;
				cin >> c;
				grid[i][j] = c;
			}
		}
		
		// 탐색
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (!check[i][j]
					&& grid[i][j] == '#')
				{// 탐색하지 않은 grid일 경우
					cnt++;
					searchSheepBunch(i, j); // 탐색 시작
				}
			}
		}
		cout << cnt << "\n";
	}
}
/*
5 5
#.##.
##.#.
#.#..
.###.
...##
5 5
##.##
#.#.#
##.##
#.#.#
#####
*/