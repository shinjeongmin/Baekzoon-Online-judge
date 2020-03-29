//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	vector<int> vec;
//	vector<int> arr;
//	
//	for (int i = 0; i < 40; i++) {
//		int temp;
//		cin >> temp;
//		vec.push_back(temp);
//	}
//
//	for (int n = 140; n < 190; n+=5)
//	{
//		cout << n / 10 << " | ";
//		for (int i = 0; i < 40; i++)
//		{
//			if (vec[i] / 10 == n)
//			{
//				if(n % 10 == 0 && 
//					vec[i] % 10 < n % 10)
//					cout << vec[i] % 10 << " ";
//				else if (n % 10 == 5 &&
//					vec[i] % 10 >= n % 10)
//					cout << vec[i] % 10 << " ";
//			}
//		}
//		cout << "\n";
//	}
//	
//	/*int temp2;
//	while (cin >> temp2)
//	{
//		arr.push_back(temp2);
//	}
//	sort(arr.begin(), arr.end());
//	for (int i = 0; i < arr.size(); i++) {
//		cout << arr[i] << " ";
//	}*/
//}
//
///*
//182 167 166 159 178 176 169 163 166 181
//171 182 172 186 171 166 170 168 154 173
//174 166 160 162 161 179 147 162 170 166
//165 178 171 169 183 149 168 177 170 163
//
//14 | 7 9
//15 | 9 4
//16 | 7 6 9 3 6 6 8 6 0 2 1 2 6 5 9 8 3
//17 | 8 6 1 2 1 0 3 4 9 0 8 1 7 0
//18 | 2 1 2 6 3
//*/