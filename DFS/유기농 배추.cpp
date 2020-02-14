#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 51;
int M, N, K, answer;
int baechu[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void dfs(int x, int y) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx<0 || nx>M - 1 || ny<0 || ny>N - 1) continue;
		if (baechu[ny][nx] && !check[ny][nx])
			dfs(nx, ny);
	}

}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (baechu[i][j] && !check[i][j]) {
				dfs(j, i);
				answer++;
			}
		}
	}
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		answer = 0;
		scanf("%d %d %d", &M, &N, &K);
		memset(baechu, 0, sizeof(baechu));
		memset(check, 0, sizeof(check));
		int x, y;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y);
			baechu[y][x] = 1;
		}
		solve();
		printf("%d\n", answer);

	}
	return 0;
}