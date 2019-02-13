#include "pch.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n ;
	string s;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int num;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << -1<<"\n";
			}
			else {
				cout << q.front()<<"\n";
				q.pop();
			}
		}
		else if (s == "empty") {
			cout << q.empty()<<"\n";
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1<<"\n";
			}
			else {
				cout << q.front()<<"\n";
			}
		}
		else if (s == "back") {
			if (q.empty()) {
				cout << -1<<"\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
		else if (s == "size") {
			cout << q.size()<<"\n";
		}
	}

	return 0;
}