#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M;
int map[MAX][MAX];
int check[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push(pair<int, int>(y, x));
	check[y][x] = 1;
	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		if ((now_y == N - 1) && (now_x == M - 1)) break;

		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i], ny = now_y + dy[i];
			if (nx <0 || nx>M - 1 || ny<0 || ny>N - 1) continue;
			if (map[ny][nx] && !check[ny][nx]) {
				check[ny][nx] = check[now_y][now_x] + 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	}
	bfs(0, 0);
	printf("%d", check[N - 1][M - 1]);
	return 0;
}