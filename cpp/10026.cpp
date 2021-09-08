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

bool nomal[101][101];
bool colorblind[101][101];
char picture[101][101];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int N, CBcnt{ 0 }, Ncnt{ 0 };

void search(int x,int y, bool blind, char color, char color2 = 'X') {
	if (blind)
		colorblind[x][y] = true;
	else
		nomal[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		if (blind){
			if (0 < x + dx[i] && x + dx[i] <= N && 
				0 < y + dy[i] && y + dy[i] <= N &&
				picture[x + dx[i]][y + dy[i]] == color ||
				picture[x + dx[i]][y + dy[i]] == color2)
			{
				if(!colorblind[x + dx[i]][y + dy[i]])
					search(x + dx[i], y + dy[i], blind, color, color2);
			}
		}
		else{
			if (0 < x + dx[i] && x + dx[i] <= N &&
				0 < y + dy[i] && y + dy[i] <= N &&
				picture[x + dx[i]][y + dy[i]] == color)
			{
				if (!nomal[x + dx[i]][y + dy[i]])
					search(x + dx[i], y + dy[i], blind, color, color2);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> picture[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!nomal[i][j]) {
				search(i, j, false, picture[i][j]);
				Ncnt++;
			}

			if (!colorblind[i][j]){
				if(picture[i][j] == 'G' ||
					picture[i][j] == 'R')
					search(i, j, true, 'G','R');
				else
					search(i, j, true, picture[i][j]);
				CBcnt++;
			}
		}
	}

	//Ãâ·Â
	cout << Ncnt << " " << CBcnt;
}
/*
G 71
R 82
82 - 71 = 11
*/