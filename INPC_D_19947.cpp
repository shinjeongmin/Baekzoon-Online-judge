#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

float H, Y;

int dp(int i) {
	if (i < 0)
		return 0;
	else if (i == 0)
		return H;
	else
	{
		return max(max(dp(i-1) * 1.05, dp(i-3) * 1.2), dp(i-5) * 1.35);
	}
}

int main()
{
	cin >> H >> Y;

	cout << dp(Y);
}