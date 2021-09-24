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
};

int ccw(xy a, xy b, xy c) {
	int ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (ans < 0) return 1; // 반시계
	else if (ans > 0) return -1; //시계
	else return 0; // 일직선
}

bool equalCCW(xy a, xy b) {
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

void compareLineInclude(xy a,xy b, xy c, xy d) {
	// 두 평행 선분에 포함되지 않는 임의의 점
	xy Z(-432977,706954); // 케이스 뚫어버리기

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
		xy ccw1(x1, y1);
		xy ccw2(x2, y2);
		xy ccw3(x3, y3);
		xy ccw4(x4, y4);
		int abc = ccw(ccw1, ccw2, ccw3);
		int abd = ccw(ccw1, ccw2, ccw4);
		int cda = ccw(ccw3, ccw4, ccw1);
		int cdb = ccw(ccw3, ccw4, ccw2);

		// 평행한 경우
		if (abc ==0 && abd == 0) {
			if (debug) cout << "같은 직선 위에 있는 경우\n";
			compareLineInclude(ccw1, ccw2, ccw3, ccw4);
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