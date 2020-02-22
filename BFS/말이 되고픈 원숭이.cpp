#include <iostream>
#include <queue>
#define MAX 200
using namespace std;

struct monkey {
	int y, x, c, h;
};

int k, w, h;
int map[MAX][MAX];
bool check[MAX][MAX][31];
const int hy[] = { -1,-2,-2,-1,1,2,2,1 };
const int hx[] = { -2,-1,1,2,2,1,-1,-2 };
const int my[] = { -1,1,0,0 };
const int mx[] = { 0,0,-1,1 };


int bfs() {
	queue<monkey> q;
	q.push({ 0,0,0,0 });
	check[0][0][0] = 1;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cc = q.front().c;
		int ch = q.front().h;
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			return cc;
		}

		if (ch < k) {
			for (int dir = 0; dir < 8; dir++) {
				int ny = cy + hy[dir];
				int nx = cx + hx[dir];
				if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1) continue;
				if (map[ny][nx] != 1 && !check[ny][nx][ch+1]) {
					q.push({ ny,nx,cc + 1, ch + 1 });
					check[ny][nx][ch+1] = true;
				}
			}
		}


		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + my[dir];
			int nx = cx + mx[dir];
			if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1) continue;
			if (map[ny][nx] != 1 && ! check[ny][nx][ch]) {
				q.push({ ny,nx,cc + 1, ch});
				check[ny][nx][ch] = true;
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d %d", &k, &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());
	return 0;
}