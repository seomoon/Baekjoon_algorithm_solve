#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		sum -= temp1;
		sum += temp2;
		if (result < sum) {
			result = sum;
		}
	}
	cout << result;

	return 0;
}