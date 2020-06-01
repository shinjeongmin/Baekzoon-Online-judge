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

// ��(#) ������ Ž���Ͽ� ��� checkó���ϴ� �Լ�
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

		// �ʱ�ȭ
		for(int i = 1; i <= H; i++)
			fill_n(check[i], (W + 1), false);
		/*for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				check[i][j] = false;*/
		cnt = 0;
 
		// �Է�
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				char c;
				cin >> c;
				grid[i][j] = c;
			}
		}
		
		// Ž��
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (!check[i][j]
					&& grid[i][j] == '#')
				{// Ž������ ���� grid�� ���
					cnt++;
					searchSheepBunch(i, j); // Ž�� ����
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