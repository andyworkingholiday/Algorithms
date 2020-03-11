#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, D, cnt, ans = 0, iter = 0;
int map[16][15], temp[16][15];
bool check[16][15];
vector<int> archor;
vector<pair<int, int>> enemy;
const int dy[] = { 0,-1,0 };
const int dx[] = { -1,0,1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	memset(check, false, sizeof(check));
	for (int j = 0; j < M; j++) check[N][j] = true;
	int k = 0;
	bool flag = false;
	while (!q.empty() && k<=D) {
		int size = q.size();
		while (size--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			if (map[cy][cx] == 1) {
				enemy.push_back({ cy,cx });
				flag = true;
				break;
			}

			for (int dir = 0; dir < 3; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (ny < 0 || nx<0 || nx>M - 1) continue;
				if (!check[ny][nx]) {
					check[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
		if (flag) break;
		k++;
	}
}

void solve() {
	bool flag = false;
	for (int i = iter; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (flag) {
		bfs(N, archor[0]);
		bfs(N, archor[1]);
		bfs(N, archor[2]);
		while (!enemy.empty()) {
			int y = enemy.back().first;
			int x = enemy.back().second;
			enemy.pop_back();
			if (map[y][x] == 1) {
				cnt++;
				map[y][x] = 0;
			}
		}

		for (int i = N - 1; i >= 1; i--) {
			for (int j = 0; j < M; j++) {
				map[i][j] = map[i - 1][j];
			}
		}
		for (int j = 0; j < M; j++) map[0][j] = 0;

		iter++;
		solve();
	}
	else return;
}


void select(int pos) {
	if (archor.size() == 3) {
		cnt = 0, iter = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = temp[i][j];
			}
		}
		solve();
		ans = max(ans, cnt);
		return;
	}

	for (int i = pos; i < M; i++) {
		archor.push_back(i);
		select(i + 1);
		archor.pop_back();
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			temp[i][j] = map[i][j];
		}
	}

	select(0);
	printf("%d\n", ans);
	return 0;
}