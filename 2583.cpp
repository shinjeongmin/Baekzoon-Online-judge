#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

bool check[100][100];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int M, N, K;
int cnt;
vector<int> area;

void fillpaper(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			check[i][j] = true;
		}
	}
}

void search(int x,int y, int k) {
	check[x][y] = true;
	area[k]++;

	for (int i = 0; i < 4; i++)
	{
		if (0 <= x + dx[i] && x + dx[i] < N &&
			0 <= y + dy[i] && y + dy[i] < M &&
			!check[x + dx[i]][y + dy[i]])
		{
			search(x + dx[i], y + dy[i], k);
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> M >> N >> K; // y,x,k

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		fillpaper(x1, y1, x2, y2);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j])
			{
				area.push_back(0);
				search(i, j, cnt);
				cnt++;
			}
		}
	}

	sort(area.begin(), area.end(), less<int>());

	cout << cnt << "\n";
	for (auto it : area) {
		cout << it << " ";
	}
}
/*
*/