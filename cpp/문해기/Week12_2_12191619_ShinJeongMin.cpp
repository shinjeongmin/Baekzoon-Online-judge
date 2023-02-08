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
			road.push_back({ A, B }); // 각 방의 {평점, 거리} 입력
		}

		sort(road.begin(), road.end(), cmp); // 점수 기준으로 내림차순 정렬
		int score = road[0].second; // 가장 가까운 거리 저장
		cnt++;
		
		for (auto room : road) {
			if (score > room.second) { // 거리 또한 내림차순으로 정렬되는 개수를 세기
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