#include <iostream>
using namespace std;
void affine(string s, int a, int b);

int main() {
	int T,a,b;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> a >> b;
		string s;
		cin >> s;

		affine(s,a,b);
	}
}

void affine(string s,int a, int b) {

	for (int i = 0; i < s.size(); i++) { //���ڿ��� �����ݺ� �ݺ� 
		s[i] -= 65; //A�� �ƽ�Ű��ȣ 65�̹Ƿ� 0���� ����� ���� 65�� ��
		s[i] = ((s[i] * a + b) % 26); //0 ~ 25������ ������ ���� �� ��ȣȭ
		s[i] += 65; //�ٽ� �ƽ�Ű��ȣ 65�� ����.
		cout << s[i];
	}
	cout << endl;
}