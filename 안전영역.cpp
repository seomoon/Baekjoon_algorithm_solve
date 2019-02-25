#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int map[101][101];
int direction[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int min_g = 100;
int max_g;
int result = 1;
vector<vector<bool>> visit;
void bfs(int x, int y, int k) { //k는 비온 리터 
	visit[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x <1 || n_x>n || n_y<1 || n_y>n) continue;
			if (map[n_x][n_y]<=k || visit[n_x][n_y]) continue;
			visit[n_x][n_y] = true;
			q.push(make_pair(n_x, n_y));
		}
	
	}

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] < min_g) {
				min_g = map[i][j];
			}
			if (map[i][j] > max_g) {
				max_g = map[i][j];
			}
		}
	}

	for (int k = min_g; k < max_g; k++) {
		visit = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visit[i][j] && map[i][j] > k) {
					bfs(i, j, k);
					count++;
				}
			}
		}
		if (count > result) {
			result = count;
		}
	}

	cout << result;
	return 0;
}