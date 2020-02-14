#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

struct xyz {
	int z, y, x;
};

int H, N, M;
int answer = -1;
int tomato[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
const int dz[] = { -1,1,0,0,0,0 }, dy[] = { 0,0,-1,1,0,0 }, dx[] = { 0,0,0,0,-1,1 };
queue<xyz> q;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		++answer;
		while (size--) {
			int curz = q.front().z;
			int cury = q.front().y;
			int curx = q.front().x;
			q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nz = curz + dz[dir];
				int ny = cury + dy[dir];
				int nx = curx + dx[dir];
				if (nz<0 || nz>H - 1 || ny<0 || ny>N - 1 || nx<0 || nx>M - 1) continue;
				if (tomato[nz][ny][nx] == 0 && !check[nz][ny][nx]) {
					tomato[nz][ny][nx] = 1;
					check[nz][ny][nx]=true;
					q.push({ nz,ny,nx });
				}
			}
		}
	}
}



int main() {
	memset(check, false, sizeof(check));
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &tomato[i][j][k]);
				if (tomato[i][j][k] == 1) {
					q.push({ i,j,k });
					check[i][j][k] = true;
				}

				else if (tomato[i][j][k] == -1) {
					check[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (!check[i][j][k]) return !printf("-1");
			}
			
		}
	}


	printf("%d\n", answer);
	return 0;
}