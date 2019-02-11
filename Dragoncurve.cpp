#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int n;
typedef struct point {
	int x;
	int y;
	int direction;
	int generation;
};
vector<point> p_a;
vector<int> direct;
bool map[102][102];
int result;

int d_a[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
int main() {
	cin >> n;
	int a, b, c, d;
	result = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		point p = { b+1, a+1, c, d };
		ㅁ
		p_a.push_back(p);
	}
	for (int i = 0; i < p_a.size(); i++) {
		direct.push_back(p_a[i].direction);
		
		for (int j = 0; j < p_a[i].generation; j++) {
			for (int k = direct.size()-1; k >= 0; k--) {
				
				direct.push_back((direct[k] + 1) % 4);
			}
		}
		//map 에 그리기 
		map[p_a[i].x][p_a[i].y] = true;
		int x = p_a[i].x;
		int y = p_a[i].y;
		for (int j = 0; j < direct.size(); j++) {
			x = x + d_a[direct[j]][0];
			y = y + d_a[direct[j]][1];
			if (x < 0 || x>101 || y < 0 || y>101) {
				continue;
			}
			map[x][y] = true;
		}
		
		direct.clear();

	}

	for (int i = 0; i < 101; i++) { 
		for (int j = 0; j < 101; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				result++;
			}
		}
	}
	
	cout << result ;


	return 0;



}