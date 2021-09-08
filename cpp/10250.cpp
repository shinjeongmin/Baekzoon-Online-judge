#include<iostream>
#include<iomanip>
using namespace std;
#define endl '\n'

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int H, W ,N;
		cin >> H >> W >> N;
		int Y = 0, X = 1;

		while (N > 0) {
			if (N > H) {
				N -= H;
				X++;
			}
			else {
				Y = N;
				break;
			}
		}
		cout << Y << setfill('0') << setw(2) <<  X << endl;
	}
}