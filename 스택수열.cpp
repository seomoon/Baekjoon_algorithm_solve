#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	stack<int> s;
	vector<int> v;
	vector<char> result;
	int num = 1;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;

		while (s.empty() || temp != s.top()) {
			if (num > n) {
				cout << "NO" << "\n";
				return 0;
			}

			s.push(num++);
			result.push_back('+');

		}
		s.pop();
		result.push_back('-');

	}
	
	if (!s.empty()) {
		cout << "NO" << "\n";
	}
	else {

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
	return 0;
}