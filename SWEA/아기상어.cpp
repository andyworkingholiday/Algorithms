#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct shark {
	int y, x, sec, mag, eat;
};

int map[20][20];
bool check[20][20];
int N;
const int dy[] = { -1,0,1,0 }, dx[] = { 0,-1,0,1 };
queue<shark> q;

bool operator<(shark a, shark b) {
	if (a.sec > b.sec) return true;
	else if (a.sec == b.sec && a.y > b.y) return true;
	else if (a.sec == b.sec && a.y == b.y && a.x > b.x) return true;
	return false;
}

int main() {
	scanf("%d", &N);
	shark baby;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				map[i][j] = 0;
				baby = { i,j,0,2,0 };
			}
		}
	}
	int ans = 0;
	while (1) {	
		priority_queue<shark> pq;
		memset(check, 0, sizeof(check));
		check[baby.y][baby.x] = true;
		q.push(baby);
		while (!q.empty()) {
			int cy = q.front().y;
			int cx = q.front().x;
			int ct = q.front().sec;
			int cm = q.front().mag;
			int ce = q.front().eat;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[dir], nx = cx + dx[dir];
				if (ny < 0 || ny > N - 1 || nx<0 || nx > N - 1) continue;
				if (!check[ny][nx]) {
					if (map[ny][nx] == 0 || map[ny][nx] == cm) {
						check[ny][nx] = true;
						q.push({ ny,nx,ct + 1,cm,ce });
					}

					else if (map[ny][nx] < cm) {
						check[ny][nx] = true;
						pq.push({ ny,nx,ct + 1,cm,ce + 1 });
					}
				}
			}
		}

		if (pq.size()==0) break;

		int mags = pq.top().mag;
		int eats = pq.top().eat;
		if (pq.top().mag == pq.top().eat) {
			mags++;
			eats = 0;
		}

		map[pq.top().y][pq.top().x] = 0;
		ans += pq.top().sec;
		baby = { pq.top().y, pq.top().x, 0, mags, eats };

	}
	printf("%d\n", ans);
	return 0;
}