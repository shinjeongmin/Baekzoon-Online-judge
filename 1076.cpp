#include <iostream>	
#include <math.h>
using namespace std;

int main() {
	string kindOfResist[] = { "black", "brown", "red", "orange", "yellow", "green"
	, "blue", "violet", "grey", "white" }; // �� ������ ������ ������� ���� string �迭
	string resist[3]; //������ ���� ���� string �迭
	long long valueOfResist = 0; //���� ���װ�

	cin >> resist[0] >> resist[1] >> resist[2];

	for (int j = 0; j < 3; j++) { // ������ ���� �����Ƿ� ���� ó��
		for (int i = 0; i < sizeof(kindOfResist) / sizeof(string); i++) {
			// sizeof(kindOfResist) / sizeof(string)�� kindOfResist�� ��� string ���ڿ��� �����̴�.
			if (!resist[j].compare(kindOfResist[i])) //j��° ������ ���� � ���ڿ��� ��ġ�ϴ� �� 10���� ���Ѵ�.
			{
				switch (j) {
				case 0: //ù��° ���� �߰�
					valueOfResist += i;
					break;
				case 1: // �ι�° ���� ù��° ���� ��ȣ�� 10�� �ڸ��� �ű� �� �߰�.
					valueOfResist *= 10;
					valueOfResist += i;
					break;
				case 2: //������ ���� ���� �� �ڸ� ���� 10^(���� ��ȣ) ��ŭ ���Ѵ�.
					valueOfResist *= pow(10, i);
					break;
				}
			}
		}
	}

	cout << valueOfResist;
}