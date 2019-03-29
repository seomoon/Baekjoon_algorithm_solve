#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
int arr[11][11];
int map[11][11];
typedef struct tree {
	int level;
	int x;
	int y;
	bool is_die;
};
bool operator <(tree a, tree b) {
	return a.level > b.level;
}
priority_queue<tree> trees;
int direction[8][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1} };
void live() {
	//봄
	vector<tree> temp_trees;
	vector<tree> die_set;
	int temp_size = trees.size();
	while(!trees.empty()) {
		tree cur = trees.top();
		trees.pop();
		if (map[cur.x][cur.y] >= cur.level) {
			map[cur.x][cur.y] -= cur.level;
			cur.level++;
			temp_trees.push_back(cur); //
		}
		else {
			cur.is_die = true;
			die_set.push_back(cur); //여름에 쓴다
		}
		
	}
	//여름
	for(int i=0; i< die_set.size(); i++){
		map[die_set[i].x][die_set[i].y] += die_set[i].level / 2; //추가 안하고 나무빼버려용!!!
	}
	//가을
	for (int i = 0; i < temp_trees.size(); i++) {
		if (temp_trees[i].level % 5 == 0) {
			for (int j = 0; j < 8; j++) {
				int n_x = temp_trees[i].x + direction[j][0];
				int n_y = temp_trees[i].y + direction[j][1];
				if (n_x<1 || n_x>n || n_y<1 || n_y>n) continue;
				tree baby = { 1, n_x, n_y, false };
				trees.push(baby);
			}
		}
		trees.push(temp_trees[i]);

	}
	//겨울
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += arr[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			map[i][j] = 5; //초기 양분
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		tree t = { l, x, y, false }; //죽으면 true로 하겠습니다~
		trees.push(t); //level을 기준으로 가장먼저 정렬이 될것입니다~
	}
	for (int i = 0; i < k; i++) {
		live();
	}
	cout << trees.size();
	return 0;
}