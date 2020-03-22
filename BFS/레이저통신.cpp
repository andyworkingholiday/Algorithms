#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int W, H;
char map[101][101];
bool check[101][101];
int dit[101][101];
vector<pair<int, int>> v;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void bfs() {
	int sy = v[0].first, sx = v[0].second;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	check[sy][sx] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			while (ny >= 0 && ny < H && nx >= 0 && nx < W) {
				if (map[ny][nx] == '*') break;
				if (!check[ny][nx]) {
					check[ny][nx] = true;
					dit[ny][nx] = dit[y][x] + 1;
					q.push({ ny,nx });
				}
				ny += dy[dir];
				nx += dx[dir];
			}
	
		}
	}
}


int main() {
	scanf("%d %d", &W, &H);
	for (int i = 0; i < H; i++) {
		scanf("%s", map + i);
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 'C') v.push_back({ i, j });
		}
	}

	bfs();
	printf("%d\n", dit[v[1].first][v[1].second] - 1);
	return 0;
}