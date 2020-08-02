#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;

int main(){
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	int hamburger = *min_element(a.begin(), a.begin()+3);
	int juice = *min_element(a.begin()+3, a.begin() + 5);
	cout << hamburger + juice - 50;
}