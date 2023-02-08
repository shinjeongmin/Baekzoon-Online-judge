#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int T, M, N, K, x, y;

struct Point {
	int X, Y;
	double dist;
	Point(int _X, int _Y, double _dist) {
		X = _X, Y = _Y, dist = _dist;
	}
};

struct cmp{
	bool operator()(Point& a, Point& b) {
		if (a.dist == b.dist) { // 거리가 같은 경우 X가 작은 것, 다음 Y가 작은 것 기준
			if (a.X == b.X)
				return a.Y < b.Y;
			return a.X < b.X;
		}
		return a.dist < b.dist; // 가까운 거리 우선
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K; // 기존 햄버거 가게 및 생성 정보, 자연수 K
		priority_queue<Point, vector<Point>, cmp> stores; // 우선순위 큐

		for (int i = 1; i <= M; i++) { // 처음부터 있는 가게
			cin >> x >> y;
			stores.push({ x,y,sqrt(pow(x,2) + pow(y,2)) });
			if (stores.size() > K) // K 보다 큰 경우 가장 먼 것 제거
				stores.pop(); // 우선순위 큐에는 K개의 가까운 가게정보만 저장
		}

		for (int i = 1; i <= N; i++) { // 새로 생기는 가게
			cin >> x >> y;
			stores.push({ x,y,sqrt(pow(x,2) + pow(y,2)) }); // 새로운 가게 우선순위 큐에 저장
			stores.pop(); // 가장 먼 가게 제거
			cout << stores.top().X << " " << stores.top().Y << "\n";
		}
	}
}

/*
3
3 3 3
-3 -1
1 3
3 3
-3 1
-1 1
4 2
3 3 1
-3 -1
1 3
3 3
-3 1
-1 1
4 2	
3 5 3
3 4
0 5
-5 0
6 -6
2 3
-4 3
7 8
0 1
*/