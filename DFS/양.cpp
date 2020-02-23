#include <iostream>
#define MAX 250
using namespace std;

int r, c;
int sheep, wolf;
char map[MAX][MAX];
bool check[MAX][MAX];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	check[y][x] = true;
	if (map[y][x] == 'o') sheep++;
	else if (map[y][x] == 'v') wolf++;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny<0 || ny> r - 1 || nx<0 || nx>c - 1) continue;
		if (map[ny][nx] != '#' && !check[ny][nx]) {
			dfs(ny, nx);
		}
	}
}


int main() {
	int ssum = 0, wsum = 0;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", map + i);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != '#' && !check[i][j]) {
				sheep = 0, wolf = 0;
				dfs(i, j);
				if (sheep != 0 || wolf != 0) {
					if (sheep > wolf) ssum += sheep;
					else wsum += wolf;
				}

			}
		}
	}

	printf("%d %d\n", ssum, wsum);
	return 0;

}