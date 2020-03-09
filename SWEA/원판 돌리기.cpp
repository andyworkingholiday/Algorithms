#include <iostream>
#include <cstring>
using namespace std;

int N, M, T, k, cnt;
int map[50][52];
bool check[50][52];
bool flag;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
double sum;

void rotate(int x, int dir, int cnt) {
	if (dir == 0) {
		while (cnt--) {
			for (int i = 0; i < N; i++) {
				if ((i + 1) % x == 0) {
					for (int j = M; j >=1; j--) {
						map[i][j + 1] = map[i][j];
					}
					map[i][1] = map[i][M + 1];
				}
			}
		}
	}

	else {
		while (cnt--) {
			for (int i = 0; i < N; i++) {
				if ((i + 1) % x == 0) {
					for (int j = 0; j < M; j++) {
						map[i][j] = map[i][j + 1];
					}
					map[i][M] = map[i][0];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		map[i][M + 1] = map[i][1];
		map[i][0] = map[i][M];
	}

}

void dfs(int y, int x) {
	check[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny<0 || ny>N - 1 || nx <0 || nx>M + 1) continue;
		if (!check[ny][nx] && (map[ny][nx] == k)) {
			map[y][x] = 0;
			map[ny][nx] = 0;
			dfs(ny, nx);
			flag = true;
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (T--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		rotate(a, b, c);
		memset(check, false, sizeof(check));
		flag = false, sum = 0, cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!check[i][j] && map[i][j]) {
					k = map[i][j];
					dfs(i, j);
				}
			}
		}

		if (!flag) {
			for (int i = 0; i < N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j]) {
						sum += map[i][j];
						cnt++;
					}
				}
			}

			sum = sum / cnt;

			for (int i = 0; i < N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j]) {
						if (double(map[i][j]) > sum) {
							map[i][j] -= 1;
						}

						else if (double(map[i][j]) < sum) {
							map[i][j] += 1;
						}

					}
				}
			}

		}
	}

	k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				k += map[i][j];
			}
			
		}
	}
	printf("%d\n", k);
	return 0;
}