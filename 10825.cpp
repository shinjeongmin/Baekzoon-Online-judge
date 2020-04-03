#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

bool comp(tuple<string, int, int, int> a, 
	tuple<string, int, int, int> b) 
{
	// ------���ǹ� Ȯ�� ���� ����--------

	// ���������� �����ϴ� ������
	if (get<1>(a) < get<1>(b))
		return false;
	//��� ������ ������ �̸��� ���� ������ �����ϴ� ������
	else if (get<1>(a) == get<1>(b) &&
		get<2>(a) == get<2>(b) &&
		get<3>(a) == get<3>(b))
		return get<0>(a) < get<0>(b);
	// ���������� ���������� ������ ���� ������ �����ϴ� ������
	else if (get<1>(a) == get<1>(b) &&
		get<2>(a) == get<2>(b))
		return get<3>(a) > get<3>(b);
	// ���������� ������ ���������� �����ϴ� ������
	else if (get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b);
	// �������� ���������� �ٸ�����̹Ƿ� ���������� ���Ҽ�
	else
		return get<1>(a) > get<1>(b);
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	vector<tuple<string, int, int, int>> KEM;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		tuple<string, int, int, int> temptuple;
		string tempstring;
		int tempint1, tempint2, tempint3;

		cin >> tempstring >> tempint1 >> tempint2 >> tempint3;
		
		get<0>(temptuple) = tempstring;
		get<1>(temptuple) = tempint1;
		get<2>(temptuple) = tempint2;
		get<3>(temptuple) = tempint3;

		KEM.push_back(temptuple);
	}

	sort(KEM.begin(), KEM.end(), comp);

	for (int i = 0; i < N; i++) 
	{
		cout << get<0>(KEM[i]) << /*" "
			<< get<1>(KEM[i]) << " "
			<< get<2>(KEM[i]) << " "
			<< get<3>(KEM[i]) << */"\n";
	}
}