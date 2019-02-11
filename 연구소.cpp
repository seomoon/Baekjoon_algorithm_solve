#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
typedef struct vi {
	int x;
	int y;
};

int result;
int sum;
int n, m;
int direction[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<vi> v_set;
bool visit[9][9];

void count_f(int map[9][9]) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!map[i][j])
				sum++;
		}
	}
	if (sum > result) {
		result = sum;
	}
}
void dfs(int temp_map[9][9], int x, int y) {
	visit[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int n_x = x + direction[k][0];
		int n_y = y + direction[k][1];

		if (n_x < 1 || n_y <1 || n_x > n || n_y > m) continue; //범위 나감

		if (temp_map[n_x][n_y] == 0) {
			temp_map[n_x][n_y] = 2;
			dfs(temp_map, n_x, n_y); //visit 을 false 할 필요가 없다
		}
	}

}

void spread(int map[9][9]) {
	
	int temp_map[9][9];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < v_set.size(); i++) {
		dfs(temp_map, v_set[i].x, v_set[i].y);
	}
	count_f(temp_map);

}

void make_wall(int map[9][9], int x, int y, int count) {
	map[x][y] = 1; //벽을 세웠다 .

	if (count == 3) {
		//확산으로 보내버려 
		spread(map);
		return;
	}
	int j = y;
	for (int i = x; i <= n; i++) {
		for (; j <= m; j++) {
			if (map[i][j] == 0) {
				make_wall(map, i, j, count+1);
				map[i][j] = 0;
			}
		}
		j = 1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int map[9][9] = {};
	cin >> n >> m;
	result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v_set.push_back({ i, j });
			}
		}
	}
	//make wall;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				make_wall(map, i, j, 1);
				map[i][j] = 0;
			}
		}
	}

	cout << result << "\n";
	return 0;
}