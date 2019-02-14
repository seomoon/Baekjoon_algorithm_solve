#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[501][501];
int visit[501][501];
int p_count;
int direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int max_num;
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	int sum = 1; //나중에 넓이 맥스랑 비교할꺼양!!

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = p.first + direction[i][0];
			int n_y = p.second + direction[i][1];
			if (n_x < 1 || n_x>n || n_y <1 || n_y >m) continue; //범위 벗어남 스킵
			if (!visit[n_x][n_y] && map[n_x][n_y] == 1) {
				visit[n_x][n_y] = true;
				sum++;
				q.push(make_pair(n_x, n_y));
			}
		}
	}
	if (sum > max_num) {
		max_num = sum;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j]) {//아직 방문 안했고 1이면 ==그림이면 시작점으로 삼아 bfs를 돈다
				bfs(i, j);
				p_count++;
			}
		}
	}
	cout << p_count << "\n" << max_num;

	return 0;
}