#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> map;
int direction[19][4][2] = { {{0, 0}, {0,1}, {0, 2}, {0,3}},
{{0, 0}, {1,0}, {2, 0}, {3,0}},
{{0, 0}, {0,1}, {1, 0}, {1,1}},
{{1, 2}, {0,1}, {0, 2}, {0,0}},
{{-1, 2}, {0,1}, {0, 2}, {0,0}},
{{-1, 0}, {0,2}, {0, 1}, {0,0}},
{{0, 2}, {0,1}, {1, 0}, {0,0}},
{{2, 0}, {1, 0}, {0, 1}, {0,0}},
{{2, 1}, {1,1}, {0, 1}, {0,0}},
{{2, -1}, {2,0}, {1, 0}, {0,0}},
{{2, 1}, {2,0}, {1, 0}, {0,0}},
{{0, 2}, {1,1}, {0, 1}, {0,0}},
{{-1, 1}, {0,2}, {0, 1}, {0,0}},
{{2, 0}, {1,1}, {1, 0}, {0,0}},
{{1, -1}, {2,0}, {1, 0}, {0,0}},
{{2, 1}, {1,1}, {1, 0}, {0,0}},
{{1, -1}, {1,0}, {0, 1}, {0,0}},
{{2, -1}, {1,-1}, {1, 0}, {0,0}},
{{1, 2}, {1,1}, {0, 1}, {0,0}} };
int result = -1;
bool ok = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k <= 19; k++) {
				int sum = 0;
				for (int l = 0; l < 4; l++) {
					int n_x = i + direction[k][l][0];
					int n_y = j + direction[k][l][1];
					if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= m) break;
					sum += map[n_x][n_y];
				}
				if (result < sum) {
					result = sum;
				}
			}
		}
	}
	cout << result;
	return 0;
}