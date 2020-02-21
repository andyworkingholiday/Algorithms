#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int n, m, ret;
int maxs = 0;
vector<int> v[MAX];
int check[MAX];
int counts[MAX];

void dfs(int n) {
	check[n] = true;
	ret++;
	for (int i = 0; i < v[n].size(); i++) {
		if (!check[v[n][i]]) dfs(v[n][i]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		ret = 0;
		dfs(i);
		counts[i] = ret;
		maxs = max(ret, maxs);
	}
	
	for (int i = 1; i <= n; i++) {
		if (counts[i] == maxs) printf("%d ", i);
	}
	return 0;
}