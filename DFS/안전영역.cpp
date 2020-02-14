#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, answer;
int maxs = 1, mins = 101;
int re_answer = -1;
int reg[101][101], region[101][101];
bool check[101][101];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny<0 || ny>N - 1 || nx<0 || nx > N - 1) continue;
		if (region[ny][nx] && !check[ny][nx]) {
			dfs(ny, nx);
		}
	}
	
}

int solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (region[i][j] && !check[i][j]) {
				dfs(i, j);
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &reg[i][j]);
			maxs = max(reg[i][j], maxs);
			mins = min(reg[i][j], mins);
			
		}
	}


	for (int k = 0; k < maxs; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				region[i][j] = 1;
			}
		}
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (reg[i][j] <= k) {
					region[i][j] = 0;
				}
			}
		}

		re_answer = max(re_answer, solve());
		answer = 0;

	}
	printf("%d", re_answer);
	return 0;

}