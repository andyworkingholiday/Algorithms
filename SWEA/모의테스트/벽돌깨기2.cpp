#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

struct brick {
	int y, x, r;
};

int N, W, H, maxs;
int all_block;
int map[15][12];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
queue<brick> q;

void copy(int a[15][12], int b[15][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = b[i][j];
		}
	}
}

int bomb(int c) {
	bool found = false;

	for (int i = 0; i < H; i++) {
		if (map[i][c]) {
			found = true;
			q.push({ i,c,map[i][c] });
			map[i][c] = 0;
			break;
		}
	}

	if (!found) return 0;

	int cnt = 0;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cr = q.front().r;
		cnt++;
		q.pop(); 

		if (cr == 1) continue;

		for (int dir = 0; dir < 4; dir++) {
			for (int r = 1; r < cr; r++) {
				int ny = cy + dy[dir] * r;
				int nx = cx + dx[dir] * r;
				if (ny<0 || ny>H - 1 || nx<0 || nx>W - 1) continue;
				if (map[ny][nx] > 0) {
					q.push({ ny,nx,map[ny][nx] });
					map[ny][nx] = 0;
				}
			}
		}
	}

	for (int j = 0; j < W; j++) {
		stack<int> s;
		for (int i = 0; i < H; i++) {
			if (map[i][j]) s.push(map[i][j]); map[i][j] = 0;
		}

		int idx = H - 1;
		while (!s.empty()) {
			int cr = s.top(); s.pop();
			map[idx][j] = cr;
			idx--;
		}
	}

	return cnt;
}

void dfs(int cnt, int sum) {
	if (cnt == N) {
		maxs = max(maxs, sum);
		return;
	}

	int temp[15][12];
	copy(temp, map);

	int bomb_sum = 0;
	for (int i = 0; i < W; i++) {
		bomb_sum = bomb(i);
		dfs(cnt + 1, sum + bomb_sum);
		copy(map, temp);
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase); 
	for (int t = 1; t <= testcase; t++) {
		scanf("%d %d %d", &N, &W, &H);
		all_block = 0, maxs = 0;
		memset(map, 0, sizeof(map));


		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) all_block++;
			}
		}

		dfs(0, 0);
		printf("#%d %d\n", t, all_block - maxs);
	}
	return 0;
}