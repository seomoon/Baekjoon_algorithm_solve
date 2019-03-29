#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int n, m;
vector<vector<int>> map;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	map = vector<vector<int>>(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j+1] = s[j]-'0';
		}
	}
	int min_size = n > m ? m : n;
	int max_k = 0;
	for (int k = 1; k <= min_size; k++) {
		for (int i = 1; i <= n-k; i++) {
			for (int j = 1; j <= m-k; j++) {
				
				int x1, y1;
				int x2, y2;
				int x3, y3;
				x1 = i;
				y1 = j + k;
				x2 = i + k;
				y2 = j;
				x3 = i + k;
				y3 = j + k;
				if (x3 > n || y3 > m) continue;
				if (map[i][j] == map[x1][y1] && map[x1][y1] == map[x2][y2] && map[x2][y2] == map[x3][y3]) {
					if (max_k < k) {
						max_k = k;
					}
				}
			}
		}
	}

	cout << (max_k+1) *( max_k +1)<< "\n";

	return 0;
}
