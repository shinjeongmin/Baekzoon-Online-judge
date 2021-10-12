#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int coor[1001][1001] = { 0, };
int N;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void init(int n) {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			coor[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			coor[i][j] = 0;
		}
	}
}

void printCoor() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			cout.width(2);
			cout.fill(' ');
			cout << coor[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void nonReachable(pair<int, int> knife, pair<int, int> gun) {
	int mark = -2;
	coor[knife.first][knife.second] = -3;
	for (int i = 0; i < 8; i++) {
		if (0 < knife.first + dx[i] && knife.first + dx[i] <= N &&
			0 < knife.second + dy[i] && knife.second + dy[i] <= N)
			coor[knife.first + dx[i]][knife.second + dy[i]] = mark;
	}
	coor[gun.first][gun.second] = -4;
	for (int i = 0; i < 8; i++) {
		pair<int, int> nextGun = make_pair(gun.first, gun.second);
		while (0 < nextGun.first + dx[i] && nextGun.first + dx[i] <= N &&
			0 < nextGun.second + dy[i] && nextGun.second + dy[i] <= N &&
			!(nextGun.first + dx[i] == knife.first && nextGun.second + dy[i] == knife.second))
		{
			coor[nextGun.first + dx[i]][nextGun.second + dy[i]] = mark;
			nextGun.first += dx[i];
			nextGun.second += dy[i];

			//cout << nextGun.first << " " << nextGun.second << " non\n";
		}
	}

	//printCoor();
}

void bfs(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	coor[start.first][start.second] = 1;
	int cnt = 1, curQsize = 0, nextQsize = 1;
	//printCoor();
	while (!q.empty()) {
		curQsize = nextQsize;
		nextQsize = 0;

		for (int j = 0; j < curQsize; j++) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				if (0 < cur.first + dx[i] && cur.first + dx[i] <= N &&
					0 < cur.second + dy[i] && cur.second + dy[i] <= N)
				{
					pair<int, int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);
					if (coor[next.first][next.second] == 0) {
						q.push(next);
						nextQsize++;
						coor[next.first][next.second] = cnt + 1;
					}
				}
			}
		}
		cnt++;
		//printCoor();
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		init(N);

		int ax, ay, bx, by, cx, cy, dx, dy;
		cin >> ax >> ay >> bx >> by;
		cin >> cx >> cy >> dx >> dy;
		nonReachable(make_pair(cx, cy), make_pair(dx, dy));
		bfs(make_pair(ax, ay));
		//printCoor();

		int answer = coor[bx][by];
		if (answer > 0)
			cout << answer - 1 << "\n";
		else
			cout << 0 << "\n";
	}
}

/*
1
5
3 1 5 3
3 4 2 4

1
8
1 1 7 4
5 4 3 6

1
8
4 1 8 5
5 4 3 6
*/