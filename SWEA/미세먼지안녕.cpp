#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct yxc {
	int y, x, k;
};

int r, c, t;
int map[50][50];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
int up, down;
queue<yxc> pluss;
queue<yxc> minuss;

void bfs(int y, int x) {
	int divid = map[y][x] / 5;
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1 || map[ny][nx] == -1) continue;
		cnt++;			
		pluss.push({ ny, nx, divid });
	}

	minuss.push({ y,x,cnt*divid });
}

void wind() {
	for (int i = up-1; i >= 0; i--) {
		map[i + 1][0] = map[i][0];
	}

	for (int i = down + 1; i < r; i++) {
		map[i - 1][0] = map[i][0];
	}

	for (int i = 1; i < c; i++) {
		map[0][i - 1] = map[0][i];
		map[r - 1][i - 1] = map[r - 1][i];
	}

	for (int i = 1; i <= up; i++) {
		map[i - 1][c - 1] = map[i][c - 1];
	}

	for (int i = r - 2; i >= down; i--) {
		map[i + 1][c - 1] = map[i][c - 1];
	}

	for (int i = c - 2; i >= 1; i--) {
		map[up][i + 1] = map[up][i];
		map[down][i + 1] = map[down][i];
	}

	map[up][1] = 0, map[down][1] = 0;
	map[up][0] = -1, map[down][0] = -1;
}


int main() {
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				up = i - 1;
				down = i;
			}
		}
	}

	
	while (t--) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					bfs(i, j);
				}
			}
		}

		while (!minuss.empty()) {
			yxc a = minuss.front();
			map[a.y][a.x] -= a.k;
			minuss.pop();
		}

		while (!pluss.empty()) {
			yxc a = pluss.front();
			map[a.y][a.x] += a.k;
			pluss.pop();
		}

		wind();

	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}