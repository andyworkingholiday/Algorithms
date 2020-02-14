#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 101;
int N, answer;
char RGB[MAX][MAX];
bool check[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs1(int y, int x) {
	if (check[y][x]) return;
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
		if (RGB[y][x] == RGB[ny][nx]) {
			dfs1(ny, nx);
		}
	}
}

void dfs2(int y, int x) {
	if (check[y][x]) return;
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
		if (RGB[y][x] == RGB[ny][nx]) {
			dfs1(ny, nx);
		}
	}
}

int solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				dfs1(i, j);
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", RGB[i]);
	}
	int ans1 = solve();
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (RGB[i][j] == 'G')
				RGB[i][j] = 'R';
		}
	}
	answer = 0;
	int ans2 = solve();

	printf("%d %d", ans1, ans2);
	return 0;
}