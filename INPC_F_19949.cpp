#include<iostream>
#include<algorithm>	
using namespace std;
#define endl '\n'

int genius[10],answer[10];
int result = 0, cnt;

bool checkContinue() {
	cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (i < 8)
		{
			// 연속 3개의 수가 같은 경우
			if (genius[i] == genius[i + 1] &&
				genius[i + 1] == genius[i + 2]) {
				return false;
			}
		}

		if (genius[i] == answer[i]) {
			cnt++;
		}
	}
	if (cnt >= 5) {
		return true;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 정답 입력
	for (int i = 0; i < 10; i++) {
		cin >> answer[i];
	}

	for (genius[0] = 1; genius[0] <= 5; genius[0]++)
	{
		for (genius[1] = 1; genius[1] <= 5; genius[1]++)
		{
			for (genius[2] = 1; genius[2] <= 5; genius[2]++)
			{
				for (genius[3] = 1; genius[3] <= 5; genius[3]++)
				{
					for (genius[4] = 1; genius[4] <= 5; genius[4]++)
					{
						for (genius[5] = 1; genius[5] <= 5; genius[5]++)
						{
							for (genius[6] = 1; genius[6] <= 5; genius[6]++)
							{
								for (genius[7] = 1; genius[7] <= 5; genius[7]++)
								{
									for (genius[8] = 1; genius[8] <= 5; genius[8]++)
									{
										for (genius[9] = 1; genius[9] <= 5; genius[9]++)
										{
											// 같은 연속 3개수가 없는 경우
											if (checkContinue()) {
												result ++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << result;
}