#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 10000
using namespace std;

struct nodeweight {
	int node, weight;
};

vector<nodeweight> tree[MAX];
bool check[MAX];
int n;
int maxs = 0, result = 0, realmax = 0;

int dfs(int start) {
	check[start] = true;
	for (int i = 0; i <tree[start].size(); i++) {
		int nnode = tree[start][i].node;
		int nweight = tree[start][i].weight;
		if (!check[nnode]) {
			maxs += nweight;
			dfs(nnode);
			result = max(result, maxs);
			maxs -= nweight;
			check[nnode] = false;
		}
	}
	return result;
}

int main() {
	scanf("%d", &n);
	int a, b, c;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		realmax = max(realmax, dfs(i));
	}
	printf("%d\n", realmax);
	return 0;
}