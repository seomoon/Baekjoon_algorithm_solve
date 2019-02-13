#include "pch.h"
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int num;
		if (s == "push_front") {
			cin >> num;
			q.push_front(num);
		}else if (s == "push_back") {
			cin >> num;
			q.push_back(num);
		}
		else if (s == "pop_front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}else if (s == "pop_back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (s == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
	}

	return 0;
}