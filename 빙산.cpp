#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int direction[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int result = 0;
vector<vector<bool>> visit;
vector<vector<int>> map;
vector<vector<int>> temp_map;
int c = 0;
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
			if (n_x <1 || n_x>n || n_y<1 || n_y>m) continue;
			if (temp_map[n_x][n_y] != 0 && !visit[n_x][n_y]) {
				visit[n_x][n_y] = true;
				q.push(make_pair(n_x, n_y));
			}	
		}
	}
}
void bfs_default(int x, int y) {
	visit[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x <1 || n_x>n || n_y<1 || n_y>m) continue;
			if (map[n_x][n_y] != 0 && !visit[n_x][n_y]) {
				visit[n_x][n_y] = true;
				q.push(make_pair(n_x, n_y));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>m;
	map = vector<vector<int>>(n+1, vector<int>(m+1));
	visit = vector<vector<bool>>(n + 1, vector<bool>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	//먼저한번 블록 몇개인지 세어본다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				c++;
				bfs_default(i, j);
			}
		}
	}
	
	while (c < 2) {
		result++;
		c = 0;
		//녹인다
		temp_map = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
		visit = vector<vector<bool>>(n + 1, vector<bool>(m + 1));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != 0) {
					temp_map[i][j] = map[i][j];
					for (int k = 0; k < 4; k++) {
						int n_x = i + direction[k][0];
						int n_y = j + direction[k][1];
						if (n_x <1 || n_x>n || n_y<1 || n_y>m) continue;
						if (map[n_x][n_y] == 0 && temp_map[i][j] >= 1) {
							temp_map[i][j]--;
						}
					}

				}
			}
		}
		int bp = 0;
		//블록 확인
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (temp_map[i][j] != 0 && !visit[i][j]) {
					c++;
					if (c >= 2) {
						bp = 1;
						break;
					}
					bfs(i, j);
				}
			}
			if (bp == 1) break;
		}
		if (c == 0) {
			result = 0; 
			break;
		}
		if (bp == 1) break;
		// temp_map을 다시 map으로 만들어
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = temp_map[i][j];
			}
		}
	
	}
	
	cout << result;
	return 0;
}