#include <iostream>
#include <vector>
using namespace std;
vector<bool> isPrimeVec;
void eratos(int n);
int numOfPrime(int min, int max);

int main() {
	int n{1};

	cin >> n; //첫번째 값 입력
	while (n != 0) // n에 0이 입력되면 반복문 탈출.
	{
		eratos(2 * n); // 2n만큼 크기를 할당한 에라토스테네스의 체 생성.
		cout << numOfPrime(n + 1, 2 * n) << "\n"; // n보다 크고, 2n이하인 소수의 개수 출력.

		cin >> n;
	}
}

// 최소, 최대값을 포함한 그 사이의 소수들의 개수를 반환하는 함수.
int numOfPrime(int min, int max) {
	int numofprime{ 0 };

	for (int i = min; i <= max; i++) {
		numofprime += isPrimeVec[i];
	}

	return numofprime;
}

void eratos(int n) {
	isPrimeVec.assign(n + 1, true); //벡터에 true값 할당
	//isPrimeVec[0] = isPrimeVec[1] = isPrimeVec[2] = true; //0,1,2에는 true할당 (소수는 아니지만)
	
	for (int i = 2; i <= static_cast<int>(n / 2); i++) 
	{
		if (isPrimeVec[i] == true) 
		{ 
			// 소수인 수만
			for (int j = 2; i * j <= n; j++) 
			{
				// n이하인 i의 배수들을 제거
				isPrimeVec[i * j] = false;
			}
		}
	}
}