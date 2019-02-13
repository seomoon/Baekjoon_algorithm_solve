#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		int index = m - 1;
		
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		while (index) {
			int temp = q.front();
			q.push(temp);
			q.pop();
			index--;
		}
		cout << q.front();
		cout << ", ";
		q.pop();

	}
	cout << ">";
	return 0;
}