#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int map[26][26];
int visit[26][26];
vector<int> count_arr;
int c; //단지수 카운트
int direction[4][2] = { {0, 1},  {0, -1}, {1, 0}, {-1, 0} };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = c;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = cur.first + direction[i][0];
			int n_y = cur.second + direction[i][1];
			if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= n) continue;
			if (visit[n_x][n_y] == 0 && map[n_x][n_y]) {
				visit[n_x][n_y] = c;
				count_arr[c - 1]++;
				q.push(make_pair(n_x, n_y));
			}
			
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visit[i][j]) {
				c++;
				count_arr.push_back(0);
				bfs(i, j);
			}
		}
	}
	cout << c << "\n";
	sort(count_arr.begin(), count_arr.end());
	for (int i = 0; i < count_arr.size(); i++) {
		cout << count_arr[i]+1 << "\n";
	}

	return 0;
}