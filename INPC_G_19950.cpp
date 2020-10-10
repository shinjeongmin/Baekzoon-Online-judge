#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int x1, y1, z1, x2, y2, z2;
	double	distance = 0;
	int stick_num;
	int sticks[101];
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	cin >> stick_num;
	for (int i = 1; i <= stick_num; i++) {
		cin >> sticks[i];
	}

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

	sort(sticks, sticks + stick_num);

	int max = *(sticks + stick_num);
	//cout << max;
	int remain = 0;
	for (int i = 1; i < stick_num; i++) {
		remain += sticks[i];
	}

	if (max - distance <= remain
		&& max + remain >= distance)
	{
		cout << "YES";
	}
	else
		cout << "NO";
}