#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y;
	int totalPride{ 0 }, remainingChick, chickSameQuantity;
	bool isXmore; //양념치킨의 수가 더 많은가?

	cin >> A >> B >> C >> X >> Y;
	chickSameQuantity = (X >= Y ? Y : X); //양념과 후라이드가 둘다 필요한 최소수량
	remainingChick = X + Y - 2 * chickSameQuantity; //둘다 필요한 최소수량을 뺀 나머지
	isXmore = (X >= Y ? true : false);

	if (A + B >= 2 * C) { //만약 양념1 + 후라이드1 >= 반반2 이면 반반으로 사는게 쌈.
		totalPride += C * 2 * chickSameQuantity;
		
		//추가적으로 최소 X,Y마리 이므로 마리수는 초과상관없음.
		//반반 2개 가격이 한마리 가격보다 싸면 반반으로 2개사는게 더 싸개 구매가능.
		if ((isXmore && A >= 2 * C) || (!isXmore && B >= 2 * C)) //양념 or fried 한마리가격보다 반반2마리가 싸거나 같으면
		{
			totalPride += 2 * C * remainingChick;
		}
		else 
		totalPride += (isXmore ? A * remainingChick : B * remainingChick);
	}
	else {
		totalPride += X * A + Y * B;
	}

	cout << totalPride;
}