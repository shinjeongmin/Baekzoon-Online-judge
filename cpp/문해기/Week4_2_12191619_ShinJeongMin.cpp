#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool debug = false;

struct xy {
	int x, y;
	xy(int a,int  b) {
		x = a;
		y = b;
	}
	bool operator==(xy other) {
		return x == other.x && y == other.y;
	}
};

int ccw(xy a, xy b, xy c) {
	int ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (ans < 0) return 1; // 반시계
	else if (ans > 0) return -1; //시계
	else return 0; // 일직선
}

void compareLineInclude(xy a,xy b, xy c, xy d) {
	// 두 평행 선분에 포함되지 않는 임의의 점 찾기
	xy Z(0,0);
	while (Z == a || Z == b || Z == c || Z == d) {
		Z.x += 3;
		Z.y += 1;
	}

	int zac = ccw(Z, a, c);
	int zad = ccw(Z, a, d);
	int zbc = ccw(Z, b, c);
	int zbd = ccw(Z, b, d);

	int zca = ccw(Z, c, a);
	int zcb = ccw(Z, c, b);
	int zda = ccw(Z, d, a);
	int zdb = ccw(Z, d, b);

	// 포함관계
	if ((zac * zad <= 0 && zbc * zbd <= 0) ||
		(zca * zcb <= 0 && zda * zdb <= 0)) {
		if(debug) cout << "포함관계 ";
		cout << 4;
	}
	// 만나지 않는 평행한 선분
	else if((zac * zad > 0 && zbc * zbd > 0) ||
		(zca * zcb > 0 && zda * zdb > 0)){
		if (debug) cout << "만나지 않는 평행한 선분 ";
		cout << 1;
	}
	// 한 점만 만나는 평행한 선분
	else if (zac * zad == 0 || zbc * zbd == 0) {
		if (debug) cout << "한 점만 만나는 평행한 선분";
		cout << 2;
	}
	// 두 평행 선분이 일부만 겹침
	else {
		if (debug) cout << "두 평행 선분이 일부만 겹침";
		cout << 3;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int x1, y1, x2, y2;
		int x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		xy a(x1, y1);
		xy b(x2, y2);
		xy c(x3, y3);
		xy d(x4, y4);
		int abc = ccw(a, b, c);
		int abd = ccw(a, b, d);
		int cda = ccw(c, d, a);
		int cdb = ccw(c, d, b);

		// 평행한 경우
		if (abc ==0 && abd == 0) {
			if (debug) cout << "같은 직선 위에 있는 경우\n";
			compareLineInclude(a, b, c, d);
		}
		// 각각 방향이 시계와 반시계로 다를경우 (교차)
		else if (abc * abd <= 0 && cda * cdb <= 0) {
			if (debug) cout << "교차 ";
			cout << 2;
		}
		// 교차안함
		else {
			if (debug) cout << "교차안함 ";
			cout << 1;
		}
		cout << "\n";
	}
}


/*
int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	double a1, b1, a2, b2;
	double X, Y;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}
		if (x1 == x2 and x3 == x4) {
			if (x1 != x3)
				cout << 1;
			else if (x1 == x3) {
				if (y1 > y2)
					swap(y1, y2);
				if (y3 > y4)
					swap(y3, y4);
				if (y1 > y4 || y3 > y2)
					cout << 1;
				if (y1 == y4 || y3 == y2)
					cout << 2;
				if (y1 <= y3 && y4 <= y2 ||
					y3 <= y1 && y2 <= y4)
					cout << 4;
				if ((y1 > y3 && y1 < y4 && y4 < y2) ||
					(y3 > y1 && y3 < y2 && y2 < y4))
					cout << 3;
			}
		}
		else if (x3 == x4) {
			a1 = (y2 - y1) / (x2 - x1);
			b1 = y1 - a1 * x1;
			Y = a1 * x3 + b1;
			if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (min(y3, y4) <= Y && Y <= max(y3, y4)))
				cout << 2;
			else
				cout << 1;
		}
		else if (x1 == x2)
		{
			a2 = (y4 - y3) / (x4 - x3);
			b2 = y3 - a2 * x3;
			Y = a2 * x1 + b2;
			if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (min(y3, y4) <= Y && Y <= max(y3, y4)))
				cout << 2;
			else
				cout << 1;
		}
		else {
			a1 = (y2 - y1) / (x2 - x1);
			b1 = y1 - a1 * x1;
			a2 = (y4 - y3) / (x4 - x3);
			b2 = y3 - a2 * x3;
			if (a1 == a2 && b1 == b2) {
				if (x1 > x4 || x3 > x2)
					cout << 1;
				if (x1 == x4 || x3 == x2)
					cout << 2;
				if ((x1 <= x3 && x4 <= x2) ||
					x3 <= x1 && x2 <= x4)
					cout << 4;
				if ((x1 > x3 && x1 < x4 && x4 < x2) ||
					x3 > x1 && x3 < x2 && x2 < x4)
					cout << 3;
			}
			else if (a1 == a2 && b1 != b2)
				cout << 1;
			else {
				X = (b2 - b1) / (a1 - a2);
				if ((x1 <= X && X <= x2) && (x3 <= X && X <= x4))
					cout << 2;
				else
					cout << 1;
			}
		}
		cout << "\n";
	}
}
*/