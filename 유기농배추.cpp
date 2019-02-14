#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int n, m, o;
int map[50][50];
bool visit[50][50];
int result = 0;
int direction[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = visit[i][j] = 0;
		}
	}
}
void bfs(int x, int y) {
	visit[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
			if (!visit[n_x][n_y] && map[n_x][n_y] == 1) {
				visit[n_x][n_y] = true;
				q.push(make_pair(n_x, n_y));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> m >> n>> o;
		result = 0;
		if(i>1) init();
		for (int j = 0; j < o; j++) {
			int t_x, t_y;
			cin >> t_y >> t_x;
			map[t_x][t_y] = 1;
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!visit[j][k] && map[j][k] == 1) {
					bfs(j, k);
					result++;
				}
			}
		}
	
		cout << result << "\n";
	
	}


	return 0;
}
