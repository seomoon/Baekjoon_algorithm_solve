#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int m, n, k;
int map[100][100];
bool visit[100][100];
int c;
vector<int> result;
int direction[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!q.empty()) {
		
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];

			if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n) continue;
			if (!map[n_x][n_y] && !visit[n_x][n_y]) {
				q.push(make_pair(n_x, n_y));
				visit[n_x][n_y] = true;
				result[c - 1]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m>>n>>k;

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = 0; j < y2- y1; j++) {
			for (int o = 0; o < x2-x1; o++) {
				map[m-y1 -j-1][x1 + o] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && !map[i][j]) {
				c++;
				result.push_back(0);
				bfs(i, j);
			}
		}
	}
	cout << c << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]+1 << " ";
	}


	return 0;
}