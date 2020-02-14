#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;

struct yxc {
	int y, x, c;
};

int N, mins = 99999;
int map[MAX][MAX];
bool check[MAX][MAX];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };


void dfs(int y, int x, int cnt) {
	map[y][x] = cnt;
	check[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) continue;
		if (map[ny][nx] && !check[ny][nx]) {
			dfs(ny, nx, cnt);
		}
	}
}

int bridge(int cnt) {
	queue<yxc> qs;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == cnt) {
				check[i][j] = true;
				qs.push({ i,j,0 });
			}
		}
	}
	int result = 0;
	while (!qs.empty()) {
		int cy = qs.front().y;
		int cx = qs.front().x;
		int count = qs.front().c;
		qs.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir], nx = cx + dx[dir];
			if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) continue;
			if (map[ny][nx] && map[ny][nx] != cnt) return count;
			else if (!map[ny][nx] && !check[ny][nx]) {
				check[ny][nx] = true;
				qs.push({ ny,nx,count + 1 });
			}
		}
	}
}


int main() {
	int answer = 999999;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !check[i][j]) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}

	for (int i = 1; i < cnt; i++) {
		memset(check, false, sizeof(check));
		answer = min(answer, bridge(i));
	}
	cout << answer << endl;
	return 0;
}