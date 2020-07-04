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
#include <climits>
using namespace std;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool check[250 + 1][250 + 1];
char yard[250 + 1][250 + 1];
int total_sheep, total_wolf;
int local_sheep{ 0 }, local_wolf{ 0 };
int R, C;

void compareSheep_Wolf(int sheep,int wolf) {
	if (sheep > wolf) {
		total_sheep += sheep;
	}
	else { //sheep <= wolf
		total_wolf += wolf;
	}
	
	return;
}

void searchFence(int x, int y) {
	check[x][y] = true;

	//양인지 늑대인지 필드인지 구분해서 수 증가
	if (yard[x][y] == 'o') {
		local_sheep++;
	}
	else if (yard[x][y] == 'v') {
		local_wolf++;
	}

	for (int i = 0; i < 4; i++) {
		// x + dx, y + dy가 yard 범위 내에 있는지 확인 및 #가 아니면 탐색 진행
		if (1 <= x + dx[i] && x + dx[i] <= R &&
			1 <= y + dy[i] && y + dy[i] <= C &&
			yard[x + dx[i]][y + dy[i]] != '#' &&
			!check[x + dx[i]][y + dy[i]]
			) {
			searchFence(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	cin >> R >> C;

	//마당에 배치
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			char object;
			cin >> object;
			yard[i][j] = object;
		}
	}

	// 한 칸씩 탐색
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// 울타리로 구분된 탐색마다 local 변수를 초기화
			local_sheep = 0, local_wolf = 0;
			if (!check[i][j]) {
				searchFence(i, j);
				compareSheep_Wolf(local_sheep, local_wolf);
			}
		}
	}

	cout << total_sheep << " " << total_wolf;
}