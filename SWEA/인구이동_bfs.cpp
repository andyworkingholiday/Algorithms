#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct yx {
	int y, x;
};

int N, L, R, answer, num;
int map[50][50];
bool check[50][50];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };


void bfs(int sy, int sx) {
	int sum = map[sy][sx];
	num = 1;
	vector<yx>v;
	queue<yx> q;
	q.push({ sy,sx });
	v.push_back({ sy,sx });
	check[sy][sx] = true;
	while (!q.empty()) {
		int qsize = q.size();		
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (ny<0 || nx<0 || ny>N - 1 || nx >N - 1) continue;
			int diff = abs(map[cy][cx] - map[ny][nx]);
			if (diff>=L && diff<=R && !check[ny][nx]) {
				check[ny][nx] = true;
				q.push({ ny,nx });
				v.push_back({ ny,nx });
				sum += map[ny][nx];
				num++;
			}
		}	
	}

	if (num == 1) return;
	int divid = sum / num;
	for (int i = 0; i < num; i++) {
		map[v[i].y][v[i].x] = divid;
	}
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	bool flag = true;
	while (flag) {
		memset(check, 0, sizeof(check));
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j]) {
					bfs(i, j);
					if (num >= 2) {
						flag = true;
					}
				}
			}
		}
		if (flag) answer++;
	}
	

	printf("%d\n", answer);
	return 0;
}