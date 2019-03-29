#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, h;
vector<vector<bool>> map;
vector<pair<int, int>> line;
int direction[2][2] = { {0, -1}, {0, 1} };
int result = -1;
bool ok = false;
bool bfs() {
	for (int i = 1; i < 2 * n; i+=2) {
		int j = 1;
		int y = i;
		while (j<=h) {
			if (y + 2  < 2 * n && map[j][y + 1] == 1) {
				y += 2;
			}
			else if (y - 2 >= 1 && map[j][y - 1] == 1) {
				y -= 2;
			}
			j++;
		}
		if (y != i) {
			return false;
		}
	}
	
	return true;
}
void dfs(int s_p_x, int s_p_y, int cnt) {
	map[s_p_x][s_p_y] = true;
	
	if ((result != -1 && result <= cnt)) {
		return;
	}
	
	if (bfs()) {
		if (cnt < result || result == -1) {
			result = cnt;
		}
		
		//ok = true;
		return;
	}
	if (cnt == 3) {
		return;
	}
	int i = s_p_x;
	int j = s_p_y;
	for (; i <= h; i++) {
		for ( ; j <= 2 * (n-1); j += 2) {
			if (map[i][j] == 0) {
				dfs(i, j, cnt+1);
				map[i][j] = false;
			}
		}
		j = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> h;
	map = vector<vector<bool>>(h + 1, vector<bool>(2 * n, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b * 2] = true;
	}
	for (int i = 1; i < 2 * n; i+=2) {
		for (int j = 1; j <= h ; j++) {
			map[j][i] = true;
		}
	}
	if (bfs()) {
		result = 0;
	}
	else {
		for (int j = 1; j <= h; j++) {
			for (int i = 0; i <= 2 *(n-1); i += 2) {
				if (map[j][i] == 0) {
					dfs(j, i, 1);
					map[j][i] = false;
				}	
			}
		}
	}
	
	cout << result;
	return 0;
}