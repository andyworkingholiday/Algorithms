#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int answer = 1;
int real_answer = 0;
int garbage[101][101];
bool check[101][101];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx<1 || nx>M || ny<1 || ny>N) continue;
		if (garbage[ny][nx] && !check[ny][nx]) {
			dfs(ny, nx);
			answer++;
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (garbage[i][j] && !check[i][j]) {
				dfs(i, j);
				real_answer = max(answer, real_answer);
				answer = 1;
			}
		}
	}
	cout << real_answer << endl;
	
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	while (K--) {
		int y, x;
		scanf("%d %d", &y, &x);
		garbage[y][x] = 1;
	}
	solve();
}