#include<iostream>
#include<algorithm>
#include<stack>
#include <queue>
using namespace std;

int Check[1000 + 1][1000 + 1];
int NextDayCheck[1000 + 1][1000 + 1];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
int DayCount{ -1 }, M, N, CurQuesize, NextQuesize;
queue<pair<int,int>> Q;

bool isAllRipen() {
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= M; i++) {
			if (Check[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> M >> N;
	
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= M; i++) {
			int input;
			cin >> input;
			Check[i][j] = input;

			if (input == 1) {
				pair<int, int> temppair(i,j);
				Q.push(temppair);
				NextQuesize++;
			}
		}
	}

	while (!Q.empty()) {
		int x{ 0 }, y{ 0 };
		CurQuesize = NextQuesize;
		NextQuesize = 0;

		for (int i = 0; i < CurQuesize; i++) {
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++) {
				if (Check[x + dx[j]][y + dy[j]] == 0 &&
					0 < x + dx[j] && x + dx[j] <= M &&
					0 < y + dy[j] && y + dy[j] <= N) {
					pair<int, int> temppair(x + dx[j], y + dy[j]);
					Q.push(temppair);
					NextQuesize++;
					Check[x + dx[j]][y + dy[j]] = 1;
				}
			}
		}
		DayCount++;
	}

	if (isAllRipen())
		cout << DayCount;
	else
		cout << -1;
}