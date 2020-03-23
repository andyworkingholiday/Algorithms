#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct zyx {
	int z, y, x, dit;
};

int map[5][5][5], rt[5][5][5], numbers[5];
int ans = 99999;
bool check[5][5][5];
const int dz[] = { -1,1,0,0,0,0 };
const int dy[] = { 0,0,-1,1,0,0 };
const int dx[] = { 0,0,0,0,-1,1 };

int bfs() {
	if (!rt[0][0][0] || !rt[4][4][4]) return 99999;

	memset(check, false, sizeof(check));
	queue<zyx> q;
	q.push({ 0,0,0,0});
	check[0][0][0] = true;
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		int dit = q.front().dit;
		if (z == 4 && y == 4 && x == 4) return dit;
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (nz < 0 || ny < 0 || nx < 0 || nz>4 || ny>4 || nx>4) continue;
			if (rt[nz][ny][nx] == 1 && !check[nz][ny][nx]) {
				check[nz][ny][nx] = true;
				q.push({ nz,ny,nx,dit + 1 });
			}
		}
	}
	return 99999;
}

void rotate(int n, int idx) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (n == 0) rt[idx][i][j] = map[numbers[idx]][i][j];
			else if (n == 1) rt[idx][i][j] = map[numbers[idx]][4-j][i];
			else if (n == 2) rt[idx][i][j] = map[numbers[idx]][4-i][4-j];
			else rt[idx][i][j] = map[numbers[idx]][j][4 - i];
		}
	}
}

void pop_rotate(int pos) {
	if (pos == 5) {
		ans = min(ans, bfs());
		return;
	}

	for (int i = 0; i < 4; i++) {
		rotate(i, pos);
		pop_rotate(pos + 1);
	}
}


void topp() {
	do {
		
		pop_rotate(0);

	} while (next_permutation(numbers, numbers + 5));
}


int main() {
	for (int i = 0; i < 5; i++) {
		numbers[i] = i;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				scanf("%d", &map[i][j][k]);
			}
		}
	}

	topp();
	if (ans == 99999) ans = -1;
	printf("%d\n", ans);
	return 0;
}