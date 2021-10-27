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
		if (a.dist == b.dist) {
			if (a.X == b.X)
				return a.Y < b.Y;
			return a.X < b.X;
		}
		return a.dist < b.dist;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		priority_queue<Point, vector<Point>, cmp> stores;

		for (int i = 1; i <= M; i++) {
			cin >> x >> y;
			stores.push({ x,y,sqrt(pow(x,2) + pow(y,2)) });
			if (stores.size() > K)
				stores.pop();
		}

		for (int i = 1; i <= N; i++) {
			cin >> x >> y;
			stores.push({ x,y,sqrt(pow(x,2) + pow(y,2)) });
			stores.pop();
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