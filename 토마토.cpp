#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int map[1001][1001];
typedef struct node {
	int x;
	int y;
	int day;
};
queue<node> q;
int direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int max_n=0;
void bfs() {
	while (!q.empty()) {
		node node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = node.x + direction[i][0];
			int n_y = node.y + direction[i][1];

			if (n_x<1 || n_x>n || n_y <1 || n_y > m) continue;
			if (map[n_x][n_y] != 0) continue;
			if (map[n_x][n_y] == 0) {
				map[n_x][n_y] = 1;
				q.push({ n_x, n_y, node.day + 1 });
				if (max_n < node.day + 1) {
					max_n = node.day + 1;
				}
			}
		}
	}
}
void check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				max_n = -1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				node n = { i, j, 0 };
				q.push(n);
			}
		}
	}
	bfs();
	check();
	cout << max_n;
	return 0;
}