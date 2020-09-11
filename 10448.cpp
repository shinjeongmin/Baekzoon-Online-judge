#include<iostream>
#include<vector>
using namespace std;

vector<int> eureka;

//1000���� ���� �ﰢ�� �̸� ���
void preCalculate(void)
{
	int N = 1;

	while ((N) * (N + 1) / 2 < 1000)
	{
		eureka.push_back(N * (N + 1) / 2);
		N++;
	}
}

// �ﰢ�� ������ ���� �� �ִ� �������� �Ǻ� ���� for��
bool triangleSum(int total)
{
	for (int i = 0; i < eureka.size(); i++){
		for (int j = 0; j < eureka.size(); j++){
			for (int k = 0; k < eureka.size(); k++) {
				if (eureka[i] + eureka[j] + eureka[k] == total)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	cin >> test_case;

	preCalculate();

	for (int i = 0; i < test_case; i++){
		int total;
		cin >> total;

		cout << triangleSum(total) << endl;
	}
}