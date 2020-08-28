#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

int n,A;
int num[50];
long long int Min;
long long int Max;
bool firstMin = true;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (firstMin)
		{
			Min = num[i];
			firstMin = false;
		}
		if (Min > num[i])
			Min = num[i];
		if (Max < num[i])
			Max = num[i];
	}

	long long int answer;
	answer = Min * Max;
	cout << answer;
}