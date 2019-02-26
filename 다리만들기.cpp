#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int direction[4][2] = { {0, -1}, { 0, 1 }, { 1, 0}, { -1, 0 }};
int n;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<vector<pair<int, int>>> ground_arr;
int g_c;
int min_n = 98765432;
void bridge() {
	if (ground_arr.size() <= 0) return;
	int len = 0;
	for (int i = 0; i < g_c-1; i++) {
		for (int j = 0; j < ground_arr[i].size(); j++) {
			for (int k = i+1; k < g_c; k++) {
				for (int l = 0; l < ground_arr[k].size(); l++) {
					int x = abs(ground_arr[i][j].first - ground_arr[k][l].first);
					int y = abs(ground_arr[i][j].second - ground_arr[k][l].second);
					len = x+y -1;
					if (len < min_n) {
						min_n = len;
					}
				}
			}
		}
	}
	
}
void bfs(int x, int y) {//±âÁØ °ª
	visit[x][y] = true;
	queue<pair<int, int>> q;
	ground_arr[g_c].push_back(make_pair(x, y));
	q.push({ x, y});
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x < 1 || n_x > n || n_y < 1 || n_y > n) continue;
			if (visit[n_x][n_y] || map[n_x][n_y]==0) continue;
			visit[n_x][n_y] = true;
			ground_arr[g_c].push_back(make_pair(n_x, n_y));
			q.push({ n_x, n_y});
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	visit = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
	int temp = (n*n)/2;
	ground_arr = vector<vector<pair<int, int>>>(temp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j] && map[i][j]) {
				bfs(i, j);
				g_c++;
			}
		}
	}
	bridge();
	
	cout << min_n;

	return 0;
}