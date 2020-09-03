#include<iostream>
using namespace std;

int main() {
	int Mon, Date;
	int DayCount{ 0 };;
	cin >> Mon >> Date;
	for (int i = Mon - 1; i > 0; i--) {
		if (i == 2)
			DayCount += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			DayCount += 30;
		else
			DayCount += 31;
	}
	DayCount += Date;
	int result = DayCount % 7;
	switch (result)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	}
}