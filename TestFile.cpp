#include<iostream>
#include<math.h>
using namespace std;

int main() {
	long long chili = 0;
	long long result = 0;
	cin >> chili;
	int i = 0;



	// ÃÖ´ë Á¦°ö¼ö
	while (chili / (long long)(pow(7, i+1)) != 0) {
		i++;
	}

	////cout << i << endl;

	for (int j = i; j >= 0; j--) {
		if(j != 0)
			while(chili >= (long long)(pow(7, j))){
				result += (long long)(pow(3,j));
				chili -= (long long)(pow(7, j));
			}
		else
			while (chili >= (long long)(pow(7, j))) {
				result += 1;
				chili -= (long long)(pow(7, j));
			}
	}

	cout << result;
}