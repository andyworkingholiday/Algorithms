#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int M, N;
string map[50];
int visit[50][50];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

int bfs(int y, int x) {
	int maxs = 0;
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(y * 10 + x);
	visit[y][x] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int cur_y = cur / 10, cur_x = cur % 10;
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur_y + dy[dir], nx = cur_x + dx[dir];
			maxs = max(maxs, visit[cur_y][cur_x]);
			if (ny<0 || ny>M - 1 || nx<0 || nx>N - 1) continue;
			if (map[ny][nx] == 'L' && visit[ny][nx]==0) {
				q.push(ny * 10 + nx);
				visit[ny][nx] = visit[cur_y][cur_x] + 1;
			}
		}
	}
	return maxs-1;
}

int main() {
	int result = 0;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
		cin >> map[i];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'L') {
				result = max(result, bfs(i, j));
			}
		}
	}
	cout << result << endl;
	return 0;
}