#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
vector<int> v[1001];
vector<int> check;

void dfs(int x) {
	if (check[x])
		return;
	
	check[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int a = v[x][i];
		dfs(a);
	}

}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			dfs(i);
			answer++;
		}
	}
}



int main() {
	
	scanf("%d %d", &N, &M);
	check = vector<int>(N + 1, 0);
	while (M--) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	solve();
	printf("%d\n", answer);
}
