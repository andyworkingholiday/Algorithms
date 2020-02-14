
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

int w, h, T;
char building[MAX][MAX];
int check[MAX][MAX];
bool Fire[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pair<int, int>> fq;
queue<pair<int, int>> q;


int bfs(int y, int x) {
	q.push(pair<int, int>(y, x));
	check[y][x] = 1;
	while (!q.empty()) {
		int num_of_fire = fq.size();
		while (num_of_fire--) {
			int fire_y = fq.front().first;
			int fire_x = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int nf_y = fire_y + dy[i];
				int nf_x = fire_x + dx[i];
				if (nf_y<0 || nf_y >h - 1 || nf_x <0 || nf_x >w - 1) continue;
				if (building[nf_y][nf_x] == '#' || Fire[nf_y][nf_x]) continue;
				fq.push(pair<int, int>(nf_y, nf_x));
				Fire[nf_y][nf_x] = true;
				building[nf_y][nf_x] = '*';
			}
		}

		int run = q.size();
		while (run--) {
			int run_y = q.front().first;
			int run_x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = run_y + dy[i];
				int nx = run_x + dx[i];
				if (ny<0 || ny >h - 1 || nx <0 || nx >w - 1)
					return check[run_y][run_x];
				if (building[ny][nx] != '.' || check[ny][nx] > 0) continue;
				q.push(pair<int, int>(ny, nx));
				check[ny][nx] = check[run_y][run_x] + 1;
			}
		}
	}
	return -1;
}


int main() {
	scanf("%d", &T);
	while (T--) {
		memset(Fire, 0, sizeof(Fire));
		memset(building, 0, sizeof(building));
		memset(check, 0, sizeof(check));
		while (!q.empty()) q.pop();
		while (!fq.empty()) fq.pop();
		int answer = 0;
		scanf("%d %d", &w, &h);
		int start_y, start_x;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				if (building[i][j] == '@') {
					start_y = i, start_x = j;
				}

				if (building[i][j] == '*' && !Fire[i][j]) {
					fq.push(pair<int, int>(i, j));
					Fire[i][j] = true;
				}
			}
		}


		answer = bfs(start_y, start_x);
		if (answer == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", answer);

	}
	return 0;
}


