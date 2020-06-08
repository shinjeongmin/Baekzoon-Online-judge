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
int Max{ INT_MIN }, Min{ INT_MAX }; //���������� �ִ�, �ּҰ�;
vector<int> NumOfArea; //������ ������ ������
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

	// ���� 1���� �Է�
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
	��Ʈ : �ƹ� ������ ���� ����� ���� ���� �ִ�.
	��, ���̰� �ּ� 1������, ��� ĭ�� 1�� ���̽�����
	�ƹ� ������ ����� �ʴ� ��찡 �ִٴ� ��.
	��� ĭ�� 1�� ��쵵 ���̰� 0�� ������ ������ ������ 1.
	*/
	if (Max == Min)
	{
		cout << 1;
		return 0;
	}

	// ������ �ִ�, �ּ� ����������ŭ ���� �ʱ�ȭ
	NumOfArea.assign(Max + 1, 0);

	// �ִ�, �ּ� ����������ŭ ������ �Է�
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