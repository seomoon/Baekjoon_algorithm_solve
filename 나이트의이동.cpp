#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int direction[8][2] = { {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {1, 2}, {2, 1} };
vector<vector<bool>> visit;
typedef struct node {
	int x;
	int y;
	int count;
};
int n;
int x_1; int y_1;
int x_2; int y_2;
int result;

void bfs(int x, int y) {//기준 값
	visit[x][y] = true;
	queue<node> q;
	q.push({x, y, 1});
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int n_x = cur.x + direction[i][0];
			int n_y = cur.y + direction[i][1];
			if (n_x == x_2 && n_y == y_2) {
				result = cur.count;
				return;
			}

			if (n_x<0 || n_x>=n || n_y<0 || n_y>=n) continue;
			if (visit[n_x][n_y]) continue;
			visit[n_x][n_y] = true;
			q.push({ n_x, n_y,  cur.count + 1});
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	
	while (t--) {
		cin >> n >> x_1 >> y_1 >> x_2 >> y_2;
		result = 0;
		visit = vector<vector<bool>>(n, vector<bool>(n));
		if (x_1 != x_2 || y_1 != y_2) { //하나라도 위치가 달라야 해! 아니면 출발지랑 목적지랑 같은경우
			bfs(x_1, y_1);
		}
		
		cout << result << "\n";
	}
	return 0;
}