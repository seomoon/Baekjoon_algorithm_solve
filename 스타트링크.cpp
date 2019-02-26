#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int f, s, g, u, d;
vector<bool> visit;
int result;
void bfs(int x) {//기준 값
	visit[s] = true;
	queue<pair<int, int>> q; //좌표 죄소이동
	q.push(make_pair(s, 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		int n_u = cur.first + u;
		int n_d = cur.first - d;
		if (n_u == g || n_d == g) {
			result = cur.second;
			return;
		}
		if (n_d >= 1) {
			if (!visit[n_d]) {
				visit[n_d] = true;
				q.push(make_pair(n_d, cur.second+1));
			}
		}
		if (n_u <= f) {
			if (!visit[n_u]) {
				visit[n_u] = true;
				q.push(make_pair(n_u, cur.second + 1));
			}
		
		}
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	visit = vector<bool>(f+1);
	bfs(s);
	if (s == g) {
		cout << 0;
	}
	else if (result ==0) {
		cout << "use the stairs";
	}
	else {
		cout << result+1;
	}
	
	return 0;
}