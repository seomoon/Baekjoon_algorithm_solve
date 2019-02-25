#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> result;
void dfs(int s, int count) {
	result.push_back(s);
	if (count == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s+1; i <=n; i++) {
		dfs(i, count+1);
		result.pop_back();
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n-m+1; i++) {
		dfs(i, 1);
		result.pop_back();
	}


	return 0;
}