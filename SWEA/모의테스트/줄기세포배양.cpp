#include <iostream>
#include <queue>
#include <cstring>
#define half 250
using namespace std;

struct cell {
	int y, x, cnt, life;
};

int map[500][500];
int N, M, K, test;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int iter = 1; iter <= testcase; iter++) {

		scanf("%d %d %d", &N, &M, &K);
		int ans = 0;
		memset(map, 0, sizeof(map));

		queue<cell> q[11];
		for (int i = 250; i < 250 + N; i++) {
			for (int j = 250; j < 250 + M; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) {
					q[map[i][j]].push({ i,j,0,map[i][j] });
				}
			}
		}

		for (int i = 0; i <= K; i++) {
			ans = 0;
			for (int j = 10; j >= 1; j--) {
				int size = q[j].size();
				ans += size;
				for (int idx = 0; idx < size; idx++) {
					cell x = q[j].front(); q[j].pop();
					if (x.cnt == 2 * x.life) {
						ans--;
						continue;
					}


					else if (x.cnt < x.life || x.cnt>x.life) {
						q[j].push({ x.y, x.x, x.cnt + 1, x.life });
					}

					else if (x.cnt == x.life) {
						q[j].push({ x.y, x.x, x.cnt + 1, x.life });
						for (int dir = 0; dir < 4; dir++) {
							int ny = x.y + dy[dir];
							int nx = x.x + dx[dir];
							if (!map[ny][nx]) {
								map[ny][nx] = x.life;
								q[j].push({ ny,nx,0,x.life });
							}
						}
					}

				}
			}
		}
		printf("#%d %d\n", iter, ans);
	}
	return 0;
}