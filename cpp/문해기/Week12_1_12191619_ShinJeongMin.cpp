#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printTri();
void init();

int T, N;
int triangle[100 + 1][100 + 1];
int resultTri[100 + 1][100 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();

		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}

		resultTri[1][1] = triangle[1][1];

		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= i; j++) {
				if (resultTri[i + 1][j] == 0) {
					resultTri[i + 1][j] = triangle[i + 1][j] + resultTri[i][j];
				}
				else {
					resultTri[i + 1][j] =
						min(resultTri[i + 1][j], triangle[i + 1][j] + resultTri[i][j]);
				}
				resultTri[i + 1][j + 1] = triangle[i + 1][j + 1] + resultTri[i][j];
			}
		}

		cout << *min_element(resultTri[N] + 1, resultTri[N] + N + 1) << "\n";
		// printTri();
	}
}

void init() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			triangle[i][j] = 0;
			resultTri[i][j] = 0;
		}
	}
}

void printTri() {
	cout << "Ãâ·Â --- \n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << resultTri[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "end --- \m";
}

/*
3
5
2
3 4
7 5 6
1 3 2 8
9 10 5 7 1
5
7
5 2
13 6 8
1 2 5 9
10 5 4 1 17
1
1
*/