#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	unsigned long long int N,result;
	cin >> N;
	while (1)
	{
		if (N % 2 == 0)
		{
			N /= 2;
		}
		else
		{
			N ++;
			result = N;
			break;
		}
	}
	if (N == 0)
		cout << 64;
	else
	{
		int cnt = 0;
		for (int i = 0; i < 64; i++)
		{
			if (result % 2 == 0)
			{
				result /= 2;
				cnt++;
			}
			else
				break;
		}
		cout << cnt;
	}
}