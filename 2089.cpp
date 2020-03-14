#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;
	cin >> N;

	if (N == 0) //0�� ����ó��
		v.push_back(0);

	while (N != 0) //0�� �ɶ� ���� ������ ���̹Ƿ� 0�� ����ó���� ����
	{
		if (N % -2 == -1) //���� �������� -1�̸� (�������� ������ 0,1�̾����)
		{
			v.push_back(1); //�������� 1�� �����
			N = N / -2 + 1; //���� ���� 1 ������Ų��.
		}
		else
		{
			v.push_back(N % -2);
			N /= -2;
		}
	}

	vector<int>::reverse_iterator iter = v.rbegin(); //���͸� �ݴ�� ����ϱ� ���� ���ͷ�����

	for (iter = v.rbegin(); iter != v.rend(); iter++)
	{
		cout << *iter;
	}
}