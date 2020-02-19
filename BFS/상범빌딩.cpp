#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct zyxm {
	int z, y, x, m;
};

int L, R, C, ans;
char map[30][30][30];
bool check[30][30][30];
const int dy[] = { 0,0,-1,1,0,0 }, dx[] = { 0,0,0,0,-1,1 }, dz[] = { -1,1,0,0,0,0 };

void bfs(zyxm start) {
	check[start.z][start.y][start.x] = true;
	queue<zyxm> q;
	q.push(start);
	while (!q.empty()) {
		int cz = q.front().z;
		int cy = q.front().y;
		int cx = q.front().x;
		int cm = q.front().m;
		q.pop(); 
		if (map[cz][cy][cx] == 'E') {
			ans = cm;
			break;
		}
		for (int dir = 0; dir < 6; dir++) {
			int nz = cz + dz[dir];
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (nz<0 || nz>L - 1 || ny<0 || ny>R - 1 || nx<0 || nx>C - 1) continue;
			if (map[nz][ny][nx] != '#' && !check[nz][ny][nx]) {
				q.push({ nz,ny,nx,cm + 1 });
				check[nz][ny][nx] = true;
			}
		}
	}
}

int main() {
	while (1) {
		ans = 0;
		zyxm start;
		memset(check, false, sizeof(check));
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				scanf("%s", &map[k][i]);
				for (int j = 0; j < C; j++) {
					if(map[k][i][j]=='S') 
						start = { k,i,j,0 };
				}
			}
		}
		bfs(start);
		if (ans != 0) printf("Escaped in %d minute(s).\n", ans);
		else printf("Trapped!\n");

	}
	return 0;
}