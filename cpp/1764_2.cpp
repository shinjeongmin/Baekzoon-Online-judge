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

	for (int i = 0; i < N; i++)
	{
		cin >> tmpstr;
		str.push_back(tmpstr);
	}
	sort(str.begin(), str.end(), less<string>());

	/*algorithm�� find �Լ��� ���⵵�� O(n)�̹Ƿ� 
	�ݺ��� ��ø�� �Ͼ�� O(n^2) �̹Ƿ� �ð��ʰ��� ��������
	binary_search �Լ��� �ð����⵵�� O(log2(n))�̹Ƿ� �ݺ����� ��ø�ǵ�
	�ð��ȿ� Ž������*/
	for (int i = 0; i < M; i++)
	{
		cin >> tmpstr;
		//binary_search ����Ž�� �˰����� �� �̿����� ������ find�� �ð��ʰ���..
		if (binary_search(str.begin(), str.end(), tmpstr))
		{
			result.push_back(tmpstr);
			count++;
		}
	}

	//������ ��� ����
	sort(result.begin(), result.end(), less<string>());
	cout << count << "\n";
	for (auto it : result) {
		cout << it << "\n";
	}
}