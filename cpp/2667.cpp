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
#include <cstring>
using namespace std;

bool check[25][25];
bool housemap[25][25];
vector<int> EachHouseNum;
int HouseNum, N;
int dx[] = { 0,0,-1,1 }, dy[] = {-1,1,0,0};

void dfs(int x, int y) {
	check[x][y] = true;
	EachHouseNum[HouseNum]++;
	for (int i = 0; i < 4; i++)
	{
		if (0 <= x + dx[i] && x + dx[i] < N &&
			0 <= y + dy[i] && y + dy[i] < N)
		{
			if (!check[x + dx[i]][y + dy[i]] &&
				housemap[x + dx[i]][y + dy[i]])
			{
				dfs(x + dx[i], y + dy[i]);
			}	
		}
	}
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N;

	// ют╥б
	for (int i = 0; i < N; i++)
	{
			string temp;
			cin >> temp;
			for (int k = 0; k < temp.size(); k++)
			{
				housemap[i][k] = temp[k] - 48;
			}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j] &&
				housemap[i][j])
			{
				EachHouseNum.push_back(0);
				dfs(i, j);
				HouseNum++;
			}
		}
	}

	sort(EachHouseNum.begin(), EachHouseNum.end(), less<int>());

	cout << HouseNum << "\n";
	for (auto it : EachHouseNum)
	{
		cout << it << "\n";
	}
}
/*
*/