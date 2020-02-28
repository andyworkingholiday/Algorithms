#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, M;
int ans = 987654321;
int map[8][8];
vector<pair<int, int>> v;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void move(int dir, int y, int x) {
	switch (dir) {
	case 0:
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
		break;

	case 1:
		for (int j = x + 1; j < M; j++) {
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
		break;

	case 2:
		for (int i = y + 1; i < N; i++) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
		break;

	case 3:
		for (int j = x - 1; j  >= 0; j--) {
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
		break;

	}
}

void copy(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void dfs(int cnt) {
	if (cnt == v.size()) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					ret++;
			}
		}
		ans = min(ans, ret);
		if (ans == 0) {
			printf("%d\n", ans);
			exit(0);
		}
		return;
	}


	int temp[8][8] = { 0, };
	copy(temp, map);

	int y = v[cnt].first;
	int x = v[cnt].second;
	int number = map[y][x];

	switch (number) {
	case 1:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			dfs(cnt + 1);
			copy(map,temp);
		}
		break;

	case 2:
		for (int dir = 0; dir < 2; dir++) {
			move(dir, y, x);
			move(dir + 2, y, x);
			dfs(cnt + 1);
			copy(map, temp);
		}
		break;

	case 3:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			move((dir + 1) % 4, y, x);
			dfs(cnt + 1);
			copy(map, temp);
		}
		break;

	case 4:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
			move((dir + 1) % 4, y, x);
			move((dir + 2) % 4, y, x);
			dfs(cnt + 1);
			copy(map, temp);
		}
		break;

	case 5:
		for (int dir = 0; dir < 4; dir++) {
			move(dir, y, x);
		}
		dfs(cnt + 1);
		copy(map, temp);
		break;
	}
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) {
				v.push_back({ i,j });
			}
		}
	}

	dfs(0);
	printf("%d\n", ans);
	return 0;
}