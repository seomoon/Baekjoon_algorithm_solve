#include "pch.h"
#include <iostream>
using namespace std;
//20억이 넘는 입력이 주어졌을경우 log시간에 해결하기위해
// pow(2, 6, 100);     return 64
//       pow(2, 3, 100);    return 8
//           pow(2, 1, 100);    return 2;
//                pow(2, 0, 100);   return 1;
long long pow(long long a, long long b, long long c) {
	if (b == 0) return 1;
	long long value =  pow(a, b / 2, c);
	value = value * value  %c;
	if (b % 2 == 0) { return value; }
	else return value * a %c;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);

	return 0;
}