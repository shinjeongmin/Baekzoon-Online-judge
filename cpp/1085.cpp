#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int arr[] = { x,y,w - x,h - y };
	int result = *min_element(arr, arr + 4);
	cout << result;
}
// ���ѽð� 9:15