#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

int changectoi(char c) {
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else
		return -1;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	string A, B;
	cin >> A >> B;
	
	// A & B
	for (int i = 0; i < A.size(); i++)
	{
		if (changectoi(A[i]) && changectoi(B[i]))
			cout << 1;
		else
			cout << 0;
	}

	cout << "\n";

	// A | B
	for (int i = 0; i < A.size(); i++)
	{
		if (changectoi(A[i]) || changectoi(B[i]))
			cout << 1;
		else
			cout << 0;
	}

	cout << "\n";

	// A ^ B
	for (int i = 0; i < A.size(); i++)
	{
		if (changectoi(A[i]) ^ changectoi(B[i]))
			cout << 1;
		else
			cout << 0;
	}

	cout << "\n";

	// ~A
	for (int i = 0; i < A.size(); i++)
	{
		if (!changectoi(A[i]))
			cout << 1;
		else
			cout << 0;
	}

	cout << "\n";

	// ~B
	for (int i = 0; i < B.size(); i++)
	{
		if (!changectoi(B[i]))
			cout << 1;
		else
			cout << 0;
	}

	cout << "\n";
}