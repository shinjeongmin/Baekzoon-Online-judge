#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <functional>
using namespace std;
int grid[21][21];
int CandidateCheckFunc();
void aroundCandidateFunc(int x, int y);

struct point_info {
	int x, y;
	point_info(int _x, int _y) {
		x = _x, y = _y;
	}
};

struct cmp {
	bool operator() (const point_info& a, const point_info& b) const
	{
		if (a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
};
set<point_info, cmp> candidate;
vector<int> check[21][21][3];

int dx[9] = { 0,0,0,1,1,1,-1,-1,-1 };
int dy[9] = { 0,1,-1,0,1,-1,0,1,-1 };
int N, Q, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> Q;
		grid[N / 2][N / 2] = grid[N / 2 + 1][N / 2 + 1] = 1;
		grid[N / 2 + 1][N / 2] = grid[N / 2][N / 2 + 1] = 2;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				aroundCandidateFunc(N / 2 + i, N / 2 + j);
			}
		}
		int turn = 1;
		for (int q = Q; q >0 ; q--) {
			int x, y;
			cin >> x >> y;
			int flag = CandidateCheckFunc();

			if (flag == 0 && turn == 0) {
				turn = flag;
			}
			if (grid[x][y] != 0)
				continue;
			if (check[x][y][turn].empty() == true)
				continue;
			for (int k = 1; k < check[x][y][turn].size(); k++) {
				int i = check[x][y][turn][k];
				for (int j = 1; j <= N; j++) {
					if (grid[x + dx[i] * j][y + dy[i] * j] == turn) {
						break;
					}
					grid[x + dx[i] * j][y + dy[i] * j] = turn;
				}
;			}
			grid[x][y] = turn;
			if (turn == 1)
				turn = 2;
			else
				turn = 1;
			candidate.erase(point_info(x, y));
			aroundCandidateFunc(x, y);
		}
		int ansCheck = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (grid[i][j] == 1)
					ansCheck += 1;
				else if (grid[i][j] == 2)
					ansCheck -= 1;
			}
		}
		if (ansCheck > 0)
			cout << 2;
		else if (ansCheck < 0)
			cout << 1;
		else
			cout << 0;
	}
}

int CandidateCheckFunc() {
	int ret = 0;
	for (auto point = candidate.begin(); point != candidate.end(); point++) {
		check[(*point).x][(*point).y][1].clear();
		check[(*point).x][(*point).y][2].clear();
		for (int i = 1; i <= 8; i++) {
			int flag = grid[(*point).x + dx[i]][(*point).y + dy[i]];
			if (flag <= 0) {
				continue;
			}
			for (int j = 2; j <= N; j++) {
				if (grid[(*point).x + dx[i] * j][(*point).y + dy[i] * j] <= 0)
					break;
				else if (grid[(*point).x + dx[i] * j][(*point).y + dy[i] * j] != flag) {
					check[(*point).x][(*point).y][grid[(*point).x + dx[i] * j][(*point).y + dy[i] * j]].push_back(i);
					ret = grid[(*point).x + dx[i] * j][(*point).y + dy[i] * j];
					break;
				}
			}
		}
	}
	return ret;
}

void aroundCandidateFunc(int x, int y) {
	for (int i = 1; i <= 8; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (grid[X][Y] == 0)
			candidate.insert(point_info(X, Y));
	}
}
