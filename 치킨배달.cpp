#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
	int x;
	int y;
};
int n, m;
vector<node> home;
vector<node> chi;
vector<bool> visit;
int h_n;
int c_n;
int ans = 987654321;
int dist(int x1, int y1, int x2, int y2) {
	int x = (x1 > x2) ? x1 - x2 : x2 - x1;
	int y = (y1 > y2) ? y1 - y2 : y2 - y1;
	return x + y;
}
void dfs(int s, int count) {
	visit[s] = true;
	
	if (count == m) { //종료조건 다 구해야해 
		int sum = 0;
		for (int i = 0; i < h_n; i++) {
			int h_min = 987654321;
			for (int j = 0; j < c_n; j++) {
				if (visit[j]) {
					int temp = dist(home[i].x, home[i].y, chi[j].x, chi[j].y);
					if (temp < h_min) {
						h_min = temp;
					}
				}
			}
			sum += h_min;
		}
		if (sum < ans) {
			ans = sum;
		}
		return;
	}
	for (int i = s+1; i < c_n; i++) {
		if (!visit[i]) {
			dfs(i, count + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 1) {
				home.push_back({ i, j });
				h_n++;
			}
			else if (temp == 2) {
				chi.push_back({ i, j });
				c_n++;
			}
		}
	}
	visit.resize(c_n);
	

	for (int i = 0; i <= c_n-m; i++){
		dfs(i, 1); // visite false해야함
		visit[i] = false;
	}
	cout << ans;
	return 0;
}