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

int N;
bool check[101][101][101];
int height[101][101][101];
int Max{ INT_MIN }, Min{ INT_MAX }; //영역높이의 최대, 최소값;
vector<int> NumOfArea; //안전한 영역의 개수들
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void raining(int x,int y, int h) {
	check[x][y][h] = true;

	for (int i = 0; i < 4; i++) {
		if (0 < x + dx[i] && x + dx[i] <= N &&
			0 < y + dy[i] && y + dy[i] <= N &&
			!check[x + dx[i]][y + dy[i]][h] &&
			height[x + dx[i]][y + dy[i]][h] > h)
		{
			raining(x + dx[i], y + dy[i], h);
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N;

	// 높이 1에만 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
				cin >> height[i][j][1];

			if (height[i][j][1] > Max)
				Max = height[i][j][1];
			if (height[i][j][1] < Min)
				Min = height[i][j][1];
		}
	}

	/*
	노트 : 아무 지역도 물에 잠기지 않을 수도 있다.
	즉, 높이가 최소 1이지만, 모든 칸이 1인 케이스에서
	아무 지역도 잠기지 않는 경우가 있다는 말.
	모든 칸이 1일 경우도 높이가 0이 되지는 않지만 개수는 1.
	*/
	if (Max == Min)
	{
		cout << 1;
		return 0;
	}

	// 높이의 최대, 최소 범위개수만큼 벡터 초기화
	NumOfArea.assign(Max + 1, 0);

	// 최대, 최소 범위개수만큼 나머지 입력
	for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = Min; k <= Max; k++)
					height[i][j][k] = height[i][j][1];
			}
		}

	for(int i = Max; i >= Min; i--){
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				if (!check[x][y][i] &&
					height[x][y][i] > i)
				{
					raining(x, y, i);
					NumOfArea[i]++;
				}
			}
		}
	}

	cout << *max_element(NumOfArea.begin(), NumOfArea.end());
}
/*
*/