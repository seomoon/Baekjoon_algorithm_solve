#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n;
int col[16];
int result;
bool promising(int cur) {
	for (int i = 1; i < cur; i++) {
		if (col[i] == col[cur] || (cur - i) == abs(col[cur] - col[i])) {
			return false;
		}
	}
	return true;
}
void dfs(int cur) {
	if (cur == n+1 ) {
		result++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		col[cur] = i;
		if (promising(cur)) {
			dfs(cur + 1);
			
		}
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(1);
	cout << result;
	return 0;
}