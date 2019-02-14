#include "pch.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n, m;
int map[101][101];
int visit[101][101];
int direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int result;
typedef struct node {
	int x;
	int y;
	int count;
};
void bfs(int x, int y) {
	node no = { x, y, 1 };
	queue<node> q;
	visit[x][y] = true;
	q.push(no);
	while (!q.empty()) {
		node temp_node = q.front();
		q.pop();
		int cur_n = temp_node.count;
		if (temp_node.x == n && temp_node.y == m) {
			result = cur_n;
		}
		
		for (int i = 0; i < 4; i++) {
			int n_x = temp_node.x + direction[i][0];
			int n_y = temp_node.y + direction[i][1];
			if (n_x<1 || n_y <1 || n_x>n || n_y>m) continue;
			if (!visit[n_x][n_y] && map[n_x][n_y] == 1) {
				q.push({ n_x, n_y, cur_n + 1 });
				visit[n_x][n_y] = true;
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
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j-1] - '0';
		}
	}
	bfs(1, 1);

	cout << result<<"\n";

	return 0;
}