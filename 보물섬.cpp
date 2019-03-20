#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int map[51][51];
int n, m;
int direction[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
typedef struct node {
	int x; int y; int time;
};
int result = 0;
void bfs(int x, int y) {
	vector<vector<bool>> visit(n+1, vector<bool>(m+1, false));
	visit[x][y] = true;
	queue<node> q;
	q.push({ x, y, 0 });
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.x + direction[i][0];
			int n_y = cur.y + direction[i][1];
			if (n_x<1 || n_x>n || n_y<1 || n_y>m) continue;
			if (visit[n_x][n_y] == true || map[n_x][n_y] == 1) continue;
			visit[n_x][n_y] = true;
			q.push({ n_x, n_y, cur.time + 1 });
			if (result < cur.time + 1) {
				result = cur.time + 1;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j <s.length(); j++) {
			if (s[j] - 'W' == 0) {
				map[i][j + 1] = 1;
			}
			else {
				map[i][j + 1] = 0;
			}
			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	cout << result;

	return 0;
}