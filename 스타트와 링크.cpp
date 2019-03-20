#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int map[20][20];
vector<bool> group;
vector<int> group1;
vector<int> group2;
int result;
void dfs(int s, int c) {
	group[s] = true;
	if (c == n / 2) {
		group1.clear();
		group2.clear();
		for (int i = 0; i < n; i++) {
			if (group[i]) {
				group1.push_back(i);
			}
			else {
				group2.push_back(i);
			}
		}
		int g1 = 0;
		int g2 = 0;
		for (int i = 0; i < group1.size()-1; i++) {
			for (int j = i + 1; j < group1.size(); j++) {
				g1 += map[group1[i]][group1[j]];
				g1 += map[group1[j]][group1[i]];
			}
		}
		for (int i = 0; i < group2.size()-1; i++) {
			for (int j = i + 1; j < group2.size(); j++) {
				g2 += map[group2[i]][group2[j]];
				g2 += map[group2[j]][group2[i]];
			}
		}
		if (result > abs(g1 - g2)) {
			result = abs(g1 - g2);
		}
		return; //그룹완료 
	}
	for (int i = s+1; i < n; i++) {
		if (group[i]==false) {
			dfs(i, c + 1);
			group[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	group = vector<bool>(n, false);
	result = 2100000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 1);
		group[i] = false;
	}
	cout << result;

	return 0;
}