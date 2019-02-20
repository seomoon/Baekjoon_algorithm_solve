#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
int min_n= 2100000000;
queue<pair<int, int>> q;
void bfs(int s, int count) {
	pair<int, int> p = { s, count };
	q.push(p);
	visit[s] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		if (cur.first == k) {
			if (min_n > cur.second) {
				min_n = cur.second;
			}
		}
		if (cur.second >= min_n) {
			continue;
		}
		if (cur.first + 1 <= 100001 && !visit[cur.first + 1]) {
			visit[cur.first + 1] = true;
			q.push(make_pair(cur.first + 1, cur.second + 1));
			
		}
		if (cur.first - 1 >= 0 && !visit[cur.first - 1]) {
			visit[cur.first - 1] = true;
			q.push(make_pair(cur.first - 1, cur.second + 1));
		}
		if (cur.first * 2 < 100001 && !visit[cur.first * 2]) {
			visit[cur.first * 2] = true;
			q.push(make_pair(cur.first * 2, cur.second + 1));
		}
		
		
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	bfs(n, 0);
	cout << min_n;
	return 0;
}