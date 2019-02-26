#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
int l, c;
vector<char> mo;
vector<char> za;
vector<bool> mo_visit;
vector<bool> za_visit;
vector<char> result;
vector<string> result_string;
void za_dfs(int z_count, int remain, int index) {
	
	if (index != -1) {
		za_visit[index] = true;
		result.push_back(za[index]);

		if (remain == 0) {
			vector<char> result_temp;
			for (int i = 0; i < result.size(); i++) {
				result_temp.push_back(result[i]);
			}
			sort(result_temp.begin(), result_temp.end());
			string s;
			for (int i = 0; i < result_temp.size(); i++) {
				
				s += result_temp[i];
			}
			result_string.push_back(s);
			return;
		}
		for (int i = index + 1; i < za.size(); i++) {
			if (!za_visit[i]) {
				za_dfs(z_count, remain - 1, i);
				za_visit[i] = false;
				result.pop_back();
			}
		}
	}
	else {
		for (int i = index + 1; i < za.size(); i++) {
			if (!za_visit[i]) {
				za_dfs(z_count, remain-1, i);
				za_visit[i] = false;
				result.pop_back();
			}
		}
	}
	

}

void mo_dfs(int m_count, int remain, int index) {

	if (index != -1) {
		mo_visit[index] = true;
		result.push_back(mo[index]);

		if (remain == 0) {
			za_dfs(l - m_count, l - m_count, -1);
		}
		for (int i = index + 1; i < mo.size(); i++) {
			if (!mo_visit[i]) {
				mo_dfs(m_count, remain - 1, i);
				mo_visit[i] = false;
				result.pop_back();
			}
		}
	}
	else {
		for (int i = index + 1; i < mo.size(); i++) {
			if (!mo_visit[i]) {
				mo_dfs(m_count, remain-1, i);
				mo_visit[i] = false;
				result.pop_back();
			}
		}
	}
	

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		if (temp - 'a' == 0 || temp - 'e' == 0 || temp - 'i' == 0 || temp - 'o' == 0 || temp - 'u' == 0) {
			mo.push_back(temp);
			mo_visit.push_back(false);
		}
		else {
			za.push_back(temp);
			za_visit.push_back(false);
		}
	}
	
	for (int i = 1; i <= l - 2 && i<=mo.size(); i++) { //¸ðÀ½°¹¼ö
		mo_dfs(i,i, -1);
	}
	sort(result_string.begin(), result_string.end());
	for (int i = 0; i < result_string.size(); i++) {
		cout << result_string[i] << "\n";
	}
	return 0;
}