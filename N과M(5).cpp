#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> arr;
int visit[9];
vector<int> result;
void dfs(int s, int count) {
	visit[s] = true;
	result.push_back(arr[s]);
	if (count == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
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
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		dfs(i, 1);
		visit[i] = false;
		result.pop_back();
	}


	return 0;
}