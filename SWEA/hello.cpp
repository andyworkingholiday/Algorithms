#include <iostream>
#include <algorithm>
using namespace std;

struct fish {
	int y;
	int x;
	int dir;
	bool life;
};

int map[4][4];
fish fishes[17];
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = {0,-1,-1,-1,0,1,1,1 };
int sum;

void swapping(int idx, int iidx) {
	fish temp = fishes[idx];
	fishes[idx].y = fishes[iidx].y;
	fishes[idx].x = fishes[iidx].x;
	fishes[iidx].y = temp.y;
	fishes[iidx].x = temp.x;
}

void fish_move() {
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].life) {
			int cy = fishes[i].y; int cx = fishes[i].x; int cdir = fishes[i].dir;
			for (int dd = 0; dd < 8; dd++) {
				int dir = (cdir + dd) % 8;
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (map[ny][nx] == -1 || ny < 0 || ny>3 || nx < 0 || nx>3) continue;
				if (map[ny][nx] == 0) {
					fishes[i].y = ny; fishes[i].x = nx;
					map[ny][nx] = i;
					map[cy][cx] = 0;					
					break;
				}
				else if (map[ny][nx] != -1) {
					swapping(i, map[ny][nx]);
					swap(map[cy][cx], map[ny][nx]);
					break;
				}

			}
		}
	}
}

void copy(int a[4][4], int b[4][4], fish c[17], fish d[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = b[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		c[i] = d[i];
	}
}

void shark_move(int sy, int sx, int dir, int score) {
	sum = max(sum, score);
	int temp[4][4];
	fish tempp[17];
	copy(temp, map, tempp, fishes);

	fish_move();

	if (score <= 22) {
		cout << score << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	for (int jump = 1; jump <= 3; jump++) {
		int ny = sy + dy[dir] * jump;
		int nx = sx + dx[dir] * jump;
		if (ny < 0 || ny>3 || nx < 0 || nx>3 || map[ny][nx]==0) continue;
		int val = map[ny][nx]; 
		int vdir = fishes[val].dir;

		fishes[val].life = false;
		map[sy][sx] = 0;
		map[ny][nx] = -1;
		shark_move(ny, nx, vdir, score + val);
		map[ny][nx] = val;
		map[sy][sx] = -1;
		fishes[val].life = true;
	}
	copy(map, temp, fishes, tempp);
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			b--;
			map[i][j] = a;
			fishes[a] = { i,j,b,true};
		}
	}

	int score = map[0][0];
	int sdir = fishes[score].dir;
	fishes[score].life = false;
	map[0][0] = -1;
	shark_move(0, 0, sdir, score);
	printf("%d\n", sum);
}