#include "pch.h"
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int boll[6] = { 0, 0, 0, 0, 0, 0 };
int direction[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int n, m, x, y, k;
int map[21][21];
vector<int> order;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n>>m>>x>>y>>k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int o;
		cin >> o;
		order.push_back(o);
	}
	boll[5] = map[x][y];
	
	int n_x = x;
	int n_y = y;
	for (int i = 0; i < order.size(); i++) {
		n_x += direction[order[i]][0];
		n_y += direction[order[i]][1];
		if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= m) {
			n_x -= direction[order[i]][0];
			n_y -= direction[order[i]][1];
			continue;
		}
		int temp[6];
		if (order[i] == 1) {
			temp[0] = boll[2];
			temp[1] = boll[1];
			temp[2] = boll[5];
			temp[3] = boll[3];
			temp[4] = boll[0];
			temp[5] = boll[4];
		}
		else if (order[i] == 2) {
			temp[0] = boll[4];
			temp[1] = boll[1];
			temp[2] = boll[0];
			temp[3] = boll[3];
			temp[4] = boll[5];
			temp[5] = boll[2];
		}
		else if (order[i] == 3) {
			temp[0] = boll[3];
			temp[1] = boll[0];
			temp[2] = boll[2];
			temp[3] = boll[5];
			temp[4] = boll[4];
			temp[5] = boll[1];
		}
		else if (order[i] == 4) {
			temp[0] = boll[1];
			temp[1] = boll[5];
			temp[2] = boll[2];
			temp[3] = boll[0];
			temp[4] = boll[4];
			temp[5] = boll[3];
		}
		if (map[n_x][n_y] == 0) {
			map[n_x][n_y] = temp[5];
		}
		else {
			temp[5] = map[n_x][n_y];
			map[n_x][n_y] = 0;
		}
		for (int j = 0; j < 6; j++) {
			boll[j] = temp[j];
		}
		cout << boll[0] << "\n";
	}
	
	return 0;

}