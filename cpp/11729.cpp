#include <iostream>
#include <string>
using namespace std;
int total_times, N;
string moving[2000000];

void move(int from, int to) {
	moving[total_times] = to_string(from) + " " + to_string(to);
	total_times++;
}

void hanoi(int n, int from, int by,int to) {
	if (n <= 1) {
		move(from, to);
	}
	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}


int main() {
	cin >> N;
	hanoi(N,1,2,3);
	cout << total_times << "\n";
	for (int i = 0; i < total_times; i++)
	{
		cout << moving[i] << "\n";
	}
}