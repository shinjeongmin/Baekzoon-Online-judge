#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() 
{

	int max; // ������ ť���� ����ū ���� �ִ� ��.
	int testcase, N, M, num{ 0 }; // N : ������ ť ����, M : �ñ��� �ε���
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		cin >> N >> M;
		num = 0;

		queue<int> printerq;
		queue<int> idxque;
		vector<int> max_ele; // ������ ť�� �߿䵵�� ������������ �迭�� ����

		for (int i = 0; i < N; i++) idxque.push(i); // �ε��� ���� ť
		for (int i = 0; i < N; i++)
			// ������ ť�� �Է°� �ֱ�
		{
			int temp;
			cin >> temp;
			printerq.push(temp);
			max_ele.push_back(temp);
		}

		sort(max_ele.begin(), max_ele.end()); // ���� �������� ����

		while (1)
		{
			// ť������ �ִ�(= ���Ϳ����� �ִ�) ã��
			max = *max_element(max_ele.begin(), max_ele.end());

			if (printerq.front() == max)
				// ť�� �ִ� �� �� �߿䵵�� ������� ���̸�.
			{
				// ������ ť�� ���� ���� ����
				printerq.pop();

				// ���Ϳ��� �ִ� �ϳ� ����
				max_ele.erase(max_ele.end() - 1); // �ּҰ�. �ε����� �ؾ��ϳ�?
				num++; //ī���� ����


				if (M == idxque.front()) 
					//
				{
					break;
				}
				// �ε��� ť�� ���� ���� ����
				idxque.pop();
			}
			else // max�� �ƴϰų�, �ε����� �ȸ°ų� �ϸ� queue ��ȯ
			{
				int temp;
				temp = printerq.front();
				printerq.push(temp);
				printerq.pop();

				temp = idxque.front();
				idxque.push(temp);
				idxque.pop();
			}
		}

		cout << num << "\n";
	}
}