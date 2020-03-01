#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;

int N, testcase;
int ans = 0;
int map[MAX][MAX];
vector<pair<int, int>> wormhole[5];

const int dy[] = { 0,-1,0,1 };
const int dx[] = { -1,0,1,0 };
int dir;

void block(int x) {
	if (x >= 1 && x <= 4) {
		if (dir == x-1) {
			dir = (dir + 1) % 4;
		}

		else if (dir == (x + 2) % 4) {
			dir = (dir + 3) % 4;
		}

		else {
			dir = (dir + 2) % 4;
		}
	}

	else {
		dir = (dir + 2) % 4;
	}
}

void pinball(int sy, int sx) {
	for (int i = 0; i < 4; i++) {
		dir = i;
		int ny = 0, nx = 0;
		int x = sx, y = sy;
		int cnt = 0;
		while (1) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (map[ny][nx] == -1 || (ny == sy && nx == sx)) {
				break;
			}
			
			if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) {
				cnt = 2 * cnt + 1;
				break;
			}

			if (map[ny][nx] >=1 && map[ny][nx] <=5) {
				cnt++;
				block(map[ny][nx]);
			}

			else if (map[ny][nx] >= 6) {
				int k = map[ny][nx];
				for (int idx = 0; idx < 2; idx++) {
					if (wormhole[k - 6][idx].first == ny && wormhole[k - 6][idx].second == nx) {
						int nn = (idx + 1) % 2;
						ny = wormhole[k - 6][nn].first;
						nx = wormhole[k - 6][nn].second;
						break;
					}
				}
			}
			y = ny;
			x = nx;
		}
		ans = max(ans, cnt);
	}
}

int main() {
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		for (int i = 0; i < 5; i++) {
			wormhole[i].clear();
		}

		memset(map, 0, sizeof(map));
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6) {
					wormhole[map[i][j] - 6].push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					pinball(i, j);
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}
	return 0;
}