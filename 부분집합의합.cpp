#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, s;
int arr[21];
int result;
void dfs(int sum, int start, int count) {
	if (count == 1) {
		if (sum == s) {
			result++;
		}
		return;
	}
	for (int i = start+1; i < n; i++) {
		dfs(sum + arr[i], i, count - 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j > n) {
				break;
			}
			dfs(arr[i], i, j);
		}
	}

	cout << result;
	return 0;
}