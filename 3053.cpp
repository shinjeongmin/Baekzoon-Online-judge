#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846;

int main() {
	double R;
	cin >> R;

	double circle_Euclid, circle_Taxi;
	circle_Euclid = R * R * M_PI;
	circle_Taxi = pow((2 * R / sqrt(2)),2); 
	//�ý� �����п��� ���� ���̴� �������� ���̰� �밢���� 1/2�� ���簢��

	cout << fixed << setprecision(6) << circle_Euclid << endl << circle_Taxi;
}