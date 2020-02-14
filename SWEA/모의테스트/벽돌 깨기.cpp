#include <iostream>
#include <queue>
#include <cstring>
#define MAX 987654321
using namespace std;

int N, H, W, T;
int tetris[15][12];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int mins = MAX;

struct yxb {
	int y, x, bomb;
};

void copy(int a[15][12], int b[15][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void fall() {
	for (int i = 0; i < W; i++) {
		queue<int> block;
		for (int j = H - 1; j >= 0; j--) {
			if (tetris[j][i] != 0) {
				block.push(tetris[j][i]);
			}
		}

		for (int r = 0; r < H; r++) tetris[r][i] = 0;

		int h = H - 1;
		while (!block.empty()) {
			tetris[h][i] = block.front();
			block.pop();
			h--;
		}

	}
}

void bfs(int w) {
	queue<yxb> q;
	int h, b;
	bool flag = true;
	for (int i = 0; i < H; i++) {
		if (tetris[i][w] != 0) {
			h = i;
			b = tetris[i][w];
			flag = false;
			break;
		}
		
	}
	if (flag) return;
	q.push({ h,w,b });
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cb = q.front().bomb;
		q.pop();
		tetris[cy][cx] = 0;
		for (int dir = 0; dir < 4; dir++) {
			for (int k = 1; k < cb; k++) {
				int ny = cy + dy[dir] * k;
				int nx = cx + dx[dir] * k;
				if (ny<0 || ny>H - 1 || nx<0 || nx>W - 1) continue;
				if (tetris[ny][nx] >= 1) {
					q.push({ ny,nx,tetris[ny][nx] });
					tetris[ny][nx] = 0;
				}
			}
		}
		
	}
	fall();
}

void start(int n) {
	if (n == 0) {
		int sum = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (tetris[i][j] != 0) sum++;
			}
		}
		mins = min(mins, sum);
		return;
	}
	int copies[15][12];
	for (int i = 0; i < W; i++) {
		copy(tetris, copies);
		bfs(i);
		start(n - 1);
		copy(copies, tetris);
	}
}

int main() {
	scanf("%d", &T);
	for (int iter = 1; iter <= T; iter++) {
		scanf("%d %d %d", &N, &W, &H);
		mins = MAX;
		memset(tetris, 0, sizeof(tetris));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &tetris[i][j]);
			}
		}

		start(N);
		printf("#%d %d\n", iter, mins);
	}
	
	
}