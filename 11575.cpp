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

	for (int i = 0; i < s.size(); i++) { //문자열의 갯수반복 반복 
		s[i] -= 65; //A가 아스키번호 65이므로 0으로 만들기 위해 65을 뺌
		s[i] = ((s[i] * a + b) % 26); //0 ~ 25범위의 값으로 만든 후 암호화
		s[i] += 65; //다시 아스키번호 65를 더함.
		cout << s[i];
	}
	cout << endl;
}