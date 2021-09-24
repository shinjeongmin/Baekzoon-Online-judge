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
	if (ans < 0) return 1; // �ݽð�
	else if (ans > 0) return -1; //�ð�
	else return 0; // ������
}

bool equalCCW(xy a, xy b) {
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

void compareLineInclude(xy a,xy b, xy c, xy d) {
	// �� ���� ���п� ���Ե��� �ʴ� ������ ��
	xy Z(-432977,706954); // ���̽� �վ������

	int zac = ccw(Z, a, c);
	int zad = ccw(Z, a, d);
	int zbc = ccw(Z, b, c);
	int zbd = ccw(Z, b, d);

	int zca = ccw(Z, c, a);
	int zcb = ccw(Z, c, b);
	int zda = ccw(Z, d, a);
	int zdb = ccw(Z, d, b);

	// ���԰���
	if ((zac * zad <= 0 && zbc * zbd <= 0) ||
		(zca * zcb <= 0 && zda * zdb <= 0)) {
		if(debug) cout << "���԰��� ";
		cout << 4;
	}
	// ������ �ʴ� ������ ����
	else if((zac * zad > 0 && zbc * zbd > 0) ||
		(zca * zcb > 0 && zda * zdb > 0)){
		if (debug) cout << "������ �ʴ� ������ ���� ";
		cout << 1;
	}
	// �� ���� ������ ������ ����
	else if (zac * zad == 0 || zbc * zbd == 0) {
		if (debug) cout << "�� ���� ������ ������ ����";
		cout << 2;
	}
	// �� ���� ������ �Ϻθ� ��ħ
	else {
		if (debug) cout << "�� ���� ������ �Ϻθ� ��ħ";
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

		// ������ ���
		if (abc ==0 && abd == 0) {
			if (debug) cout << "���� ���� ���� �ִ� ���\n";
			compareLineInclude(ccw1, ccw2, ccw3, ccw4);
		}
		// ���� ������ �ð�� �ݽð�� �ٸ���� (����)
		else if (abc * abd <= 0 && cda * cdb <= 0) {
			if (debug) cout << "���� ";
			cout << 2;
		}
		// ��������
		else {
			if (debug) cout << "�������� ";
			cout << 1;
		}
		cout << "\n";
	}
}