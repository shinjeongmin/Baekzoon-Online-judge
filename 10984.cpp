#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T, N, C, total_credit{ 0 };
	double G, total_grade{ 0 }, GPA{ 0 };
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		total_credit = 0, total_grade = 0;
		for (int n = 0; n < N; n++) {
			cin >> C >> G;
			total_credit += C; //�� �̼�����
			total_grade += G * C; // ��� x �����̼�����
		}
		cout << fixed << setprecision(1) << total_credit << " " << total_grade / total_credit << endl;
	}
}