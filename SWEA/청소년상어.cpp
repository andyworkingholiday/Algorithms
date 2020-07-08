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
const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
fish fishes[17];
int result;

void fish_swap(fish &a, fish& b) {
	fish temp;
	int anum = map[a.y][a.x]; int bnum = map[b.y][b.x];
	map[a.y][a.x] = bnum; map[b.y][b.x] = anum;
	temp.y = a.y; temp.x = a.x;
	a.y = b.y; a.x = b.x;
	b.y = temp.y; b.x = temp.x;
}

void fish_move() {
	for (int i = 1; i <= 16; i++) {
		if (!fishes[i].life) continue;
		int cy = fishes[i].y; int cx = fishes[i].x; int cd = fishes[i].dir;
		for (int dd = 0; dd < 8; dd++) {
			int dir = (cd + dd) % 8;
			int ny = cy + dy[dir]; int nx = cx + dx[dir];
			if (ny < 0 || ny>3 || nx < 0 || nx>3 || map[ny][nx] == -1) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = i; map[cy][cx] = 0;
				fishes[i].y = ny; fishes[i].x = nx; fishes[i].dir = dir;
				break;
			}

			else if (map[ny][nx] >= 1) {
				fishes[i].dir = dir;
				int another_fish = map[ny][nx];
				fish_swap(fishes[i], fishes[another_fish]);
				break;
			}

		}
	}
}

void copymap(int a[4][4], int b[4][4], fish c[17], fish d[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = b[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) 
		c[i] = d[i];
}

void shark_move(int y, int x, int dir, int score) {
	result = max(result, score);

	int temp[4][4];
	fish tempp[17];
	copymap(temp, map, tempp, fishes);
	fish_move();

	for (int jump = 1; jump <= 3; jump++) {
		int ny = y + dy[dir] * jump;
		int nx = x + dx[dir] * jump;
		if (ny < 0 || ny>3 || nx < 0 || nx>3) break;
		if (map[ny][nx] == 0) continue;

		int val = map[ny][nx]; int sdir = fishes[val].dir;
		map[y][x] = 0;
		map[ny][nx] = -1;
		fishes[val].life = false;
		shark_move(ny, nx, sdir, score + val);
		fishes[val].life = true;
		map[ny][nx] = val;
		map[y][x] = -1;
	}

	copymap(map, temp, fishes, tempp);
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			b--;
			fishes[a] = { i,j,b,true };
			map[i][j] = a;
		}
	}

	int score = map[0][0];
	map[0][0] = -1;
	fishes[score].life = false;
	int ssdir = fishes[score].dir;
	shark_move(0, 0, ssdir, score);

	printf("%d\n", result);
	return 0;
}