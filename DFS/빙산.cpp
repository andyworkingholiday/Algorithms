#include <iostream>
#include <cstring>
#define MAX 301
using namespace std;

int N, M, year;
int ice[MAX][MAX], copy_ice[MAX][MAX];
bool check[MAX][MAX];

const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };


void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ice[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir], nx = j + dx[dir];
					if (ny<0 || ny>N - 1 || nx <0 || nx>M - 1) continue;
					if (ice[ny][nx] == 0) {
						if (copy_ice[i][j] > 0) {
							copy_ice[i][j]--;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ice[i][j]=copy_ice[i][j];
		}
	}

}

void dfs(int y, int x) {
	check[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1) continue;
		if (!check[ny][nx] && copy_ice[ny][nx] > 0)
			dfs(ny, nx);
	}
}

int main() {
	int year = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ice[i][j]);
			copy_ice[i][j] = ice[i][j];
		}
	}
	
	while (1) {
		memset(check, 0, sizeof(check));
		bool flag = false;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_ice[i][j] > 0 && !check[i][j]) {
					cnt++;
					if (cnt == 2) {
						flag = true;
						break;
					}
					dfs(i, j);
				}
			}
		}
		if (flag) break;
		if (cnt == 0) {
			year = 0;
			break;
		}
		year++;
		melt();
	}
	printf("%d\n", year);
	return 0;
}