#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, A, B, last, cnt;
vector<pair<int,int>> road;

bool cmp(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cnt = 0;
		road = vector<pair<int, int>>();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A >> B;
			road.push_back({ A, B }); // �� ���� {����, �Ÿ�} �Է�
		}

		sort(road.begin(), road.end(), cmp); // ���� �������� �������� ����
		int score = road[0].second; // ���� ����� �Ÿ� ����
		cnt++;
		
		for (auto room : road) {
			if (score > room.second) { // �Ÿ� ���� ������������ ���ĵǴ� ������ ����
				score = room.second;
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}

/*
3
7
90 1500
50 500
100 3000
5 4500
10 3100
85 700
20 4000
3
50 1000
20 3000
30 2000
3
50 1000
60 3000
20 2000
*/