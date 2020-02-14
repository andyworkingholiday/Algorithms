#include <iostream>
#include <cstring>
using namespace std;

int N;
int nodes[101][101];
bool check[101];

void dfs(int x) {
	for (int i = 0; i < N; i++) {
		if (nodes[x][i] && !check[i]) {
			check[i] = true;
			dfs(i);
		}
	}

}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &nodes[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		memset(check, 0, sizeof(check));
		dfs(i);
		for (int j = 0; j < N; j++) {
			if (check[j])
				nodes[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", nodes[i][j]);
		}
		printf("\n");
	}
	return 0;
}