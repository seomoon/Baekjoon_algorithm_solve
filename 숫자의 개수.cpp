#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	int result;
	int count[10] = { 0, };
	cin >> a >> b >> c;
	result = a * b * c;
	while (result > 0) {
		count[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << count[i] << "\n";
	}

	return 0;
}