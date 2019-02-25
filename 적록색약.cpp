#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int direction[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int n;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<vector<bool>> visit2;
int n_count;
int s_count;
void bfs(int x, int y, int value) {//기준 값
	visit[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x<1 || n_x>n || n_y<1 || n_y>n) continue;
			if (visit[n_x][n_y]) continue;
			if (map[n_x][n_y] == value) {
				visit[n_x][n_y] = true;
				q.push(make_pair(n_x, n_y));
			}
		}
	}
}
void bfs2(int x, int y, int value) {//기준 값

		visit2[x][y] = true;
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int n_x = cur.first + direction[i][0];
				int n_y = cur.second + direction[i][1];
				if (n_x<1 || n_x>n || n_y<1 || n_y>n) continue;
				if (visit2[n_x][n_y]) continue;
				if (value==2 && map[n_x][n_y] == value) {
					visit2[n_x][n_y] = true;
					q.push(make_pair(n_x, n_y));
				}
				if (value!=2 && map[n_x][n_y] != 2) {
					visit2[n_x][n_y] = true;
					q.push(make_pair(n_x, n_y));
				}
			}
		}
	
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> n;
	map = vector<vector<int>>(n+1, vector<int>(n+1));
	visit = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
	visit2 = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] - 'R' == 0) map[i][j] = 0;
			if (s[j - 1] - 'G' == 0) map[i][j] = 1;
			if (s[j - 1] - 'B' == 0) map[i][j] = 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit[i][j]) {
				n_count++;
				bfs(i, j, map[i][j]); //기준값
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visit2[i][j]) {
				s_count++;
				bfs2(i, j, map[i][j]); //기준값
			}
		}
	}
	cout << n_count<<" "<<s_count;
	return 0;
}