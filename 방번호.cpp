#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int result = 0;
	int count[9] = { 0,  };
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - '0' == 9) {
			if (count[6] == 0) {
				result++;
				for (int j = 0; j < 9; j++) {
					count[j]++;
				}
				count[6]++;
			}
			count[6]--;
		}
		else {
			if (count[s[i] - '0'] == 0) {
				result++;
				for (int j = 0; j < 9; j++) {
					count[j]++;
				}
				count[6]++;
			}
			count[s[i] - '0']--;
		}	
	}
	cout << result;

	return 0;
}