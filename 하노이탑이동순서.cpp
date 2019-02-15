#include "pch.h"
#include <iostream>
using namespace std;

void h(int from, int to, int n) {
	
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	int c = 6 - from - to; //거쳐갈곳
	h(from, c, n - 1);
	cout << from << " " << to << "\n";
	h(c, to, n-1);


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (1<<n)-1<< "\n";
	h(1, 3, n);
	return 0;
}