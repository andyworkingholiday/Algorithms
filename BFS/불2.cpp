#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

struct yxc {
	int y, x, c;
};

const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
int r, c, ans;
char map[MAX][MAX];
bool check[MAX][MAX];
bool fire[MAX][MAX];
queue<yxc> jq;
queue<yxc> fq;

int bfs() {
	
	while (!jq.empty()) {
		int jsize = jq.size();
		int fsize = fq.size();

		while (fsize--) {
			int fy = fq.front().y;
			int fx = fq.front().x;
			fq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = fy + dy[dir];
				int nx = fx + dx[dir];
				if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1) continue;
				if (map[ny][nx] != '#' && !fire[ny][nx]) {
					fq.push({ ny,nx,0 });
					fire[ny][nx] = true;
					map[ny][nx] = 'F';
				}
			}
		}
		while (jsize--) {
			int cy = jq.front().y;
			int cx = jq.front().x;
			int ct = jq.front().c;
			jq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1) {
					return ct + 1;
				}
				if (map[ny][nx] == '.' && !check[ny][nx]) {
					jq.push({ ny,nx,ct + 1 });
					check[ny][nx] = true;
				}
			}
		}

	}
	return -1;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'J') {
				jq.push({ i,j,0 });
				check[i][j] = true;
			}
			else if (map[i][j] == 'F') {
				fq.push({ i,j,0 });
				fire[i][j] = true;
			}
		}
	}
	ans = bfs();
	if (ans == -1) printf("IMPOSSIBLE\n");
	else printf("%d\n", ans);
	return 0;
}