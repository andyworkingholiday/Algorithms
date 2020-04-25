#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct yx {
	int y, x;
};

int N, M, answer = 0;
int map[8][8];
bool check[8][8];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void bfs() {
	queue<yx> q;
	int temp[8][8], ret = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
			if (map[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir], nx = cx + dx[dir];
			if (ny <0 || ny>N - 1 || nx<0 || nx>M - 1) continue;
			if (!temp[ny][nx] && !check[ny][nx]) {
				temp[ny][nx] = 2;
				check[ny][nx] = true;
				q.push({ ny,nx });
			}
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!temp[i][j]) ret++;
		}
	}
	answer = max(ret, answer);
}


void pick(int posy, int posx, int counts) {
	if (counts == 3) {
		bfs();
		return;
	}

	for (int i = posy; i < N; i++) {
		for (int j = posx; j < M; j++) {
			if (!map[i][j]) {
				map[i][j] = 1;
				pick(i, j, counts + 1);
				map[i][j] = 0;
			}
		}
		posx = 0;
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	pick(0, 0, 0);
	printf("%d\n", answer);
	return 0;
}