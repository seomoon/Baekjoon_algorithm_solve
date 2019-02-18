#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int n, m;

vector<int> result;
void dfs(int cur, int count) {
	
	result.push_back(cur);
	if (count == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cur; i <= n; i++) {
			dfs(i, count + 1);
			result.pop_back();
		
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
		result.pop_back();
	}
	return 0;
}