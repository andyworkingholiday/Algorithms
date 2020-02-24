#include <iostream>
#include <cstring>
using namespace std;

int h, w, answer;
int map[50][50];
bool check[50][50];
const int dy[] = { -1,-1,-1,0,1,1,1,0 };
const int dx[] = { 1,0,-1,-1,-1,0,1,1 };


void dfs(int y, int x) {
	check[y][x] = true;
	for (int dir = 0; dir < 8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny<0 || ny> h - 1 || nx<0 || nx>w - 1) continue;
		if (map[ny][nx] == 1 && !check[ny][nx]) {
			dfs(ny, nx);
		}
	}

}

int main() {

	while (1) {
		scanf("%d %d", &w, &h);
		memset(check, false, sizeof(check));
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}


		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !check[i][j]) {
					dfs(i, j);
					answer++;
				}
			}

		}
		printf("%d\n", answer);
		answer = 0;
	}
	return 0;

}