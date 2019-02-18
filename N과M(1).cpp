#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool visit[9];
vector<int> result;
void dfs(int cur, int count) {
	visit[cur] = true;
	result.push_back(cur);
	if (count == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i, count + 1);
			visit[i] = false;
			result.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
		visit[i] = false;
		result.pop_back();
	}
	return 0;
}