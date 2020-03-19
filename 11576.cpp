#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int A, B, m, total{ 0 };
	//total은 A진법의 수를 10진법으로 나타낸 값이다.
	cin >> A >> B >> m;
	
	for (int i = m - 1; i >= 0; i--) 
	{ // 높은 자리수부터이다. i는 A^i 용으로 사용하므로 m - 1부터 0 까지 순환
		int temp;
		cin >> temp;
		total += pow(A, i) * temp;
	}

	int n{ 0 }; // A진법에서 m처럼 B진법으로는 몇의 자리까지 존재해야하는지.
	while (pow(B, n) < total) {
		n++;
	}n--; 
	/* B의 n자리수가 십진수로 바꾼값보다 큰 값에서 반복문을 탈출하므로
	n에서 1을 빼야함.*/

	while (total > 0 || n >=0) {
		cout << total / static_cast<int>(pow(B,n)) << " "; 
		// 도합된 십진수를 B의 n승으로 나누어 B의 n자리수가 몇인지 구하는 식.
		total %= static_cast<int>(pow(B,n));
		//n승으로 나누고 난 후 십진수의 나머지값.
		n--;
	}
}