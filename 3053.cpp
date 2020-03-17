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
	//택시 기하학에서 원의 넓이는 반지름의 길이가 대각선의 1/2인 정사각형

	cout << fixed << setprecision(6) << circle_Euclid << endl << circle_Taxi;
}