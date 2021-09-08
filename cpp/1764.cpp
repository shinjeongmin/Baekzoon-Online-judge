#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N, M, count{ 0 };

	cin >> N >> M;

	vector<string> str;
	/*���(�躸���)�� ��� ����*/
	vector<string> result;
	string tmpstr;

	for (int i = 0; i < N + M; i++)
	{
		cin >> tmpstr;
		str.push_back(tmpstr);
	}

	//sort �Լ��� �̿��� �������� ����, less�� ǥ�� �� library
	sort(str.begin(), str.end(), less<string>());

	// ��� ���ڿ��� �ް� �����ϸ� ���� �̸��� �پ������Ƿ�
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == str[i + 1])
		{
			count++;
			result.push_back(str[i]);
		}
	}

	cout << count << "\n";
	for (auto it : result) {
		cout << it << "\n";
	}
}