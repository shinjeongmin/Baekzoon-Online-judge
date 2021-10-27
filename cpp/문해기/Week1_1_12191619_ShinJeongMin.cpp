#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, result;
	int K, T;
	char arr[1001][1001];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> str;
		cin >> K;

		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				arr[i][j] = '0';
			}
		}

		int y = 0, x = 0;
		for (int i = 0; (unsigned int)i < str.size(); i++) {
			arr[x][y] = str[i];

			if ((i + 1) % K == 0) {
				y++;
			}
			else if ((i / K) % 2 == 1) { 
				x--;
			}
			else {
				x++;
			}
		}

		//// 출력 테스트
		//for (int i = 0; i < 20; i++) {
		//	for (int j = 0; j < 20; j++) {
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		result = "";
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				if (arr[i][j] != '0')
					result += arr[i][j];
			}
		}
		cout << result << "\n";
	}

	return 0;
}
