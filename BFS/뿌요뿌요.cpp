#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

char map[12][6];
bool check[12][6];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void dfs(int y, int x) {
	check[y][x] = true;
	q.push({ y,x });
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny>11 || nx < 0 || nx>5) continue;
		if (map[ny][nx] == map[y][x] && !check[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

void sorting(char a[12][6]) {
	for (int j = 0; j < 6; j++) {
		stack<int> s;
		for (int i = 0; i < 12; i++) {
			if (a[i][j] != '.') {
				s.push(a[i][j]);
			}
			a[i][j] = '.';
		}

		int idx = 11;
		while (!s.empty()) {
			a[idx][j] = s.top();
			s.pop();
			idx--;
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		scanf("%s", map + i);


	int ret = 0;

	bool flag = true;
	while (1) {
		flag = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !check[i][j]) {
					dfs(i, j);
					if (q.size()>=4) {
						flag = true;
						while (!q.empty()) {
							map[q.front().first][q.front().second] = '.';
							q.pop();
						}
					}
					else {
						while (!q.empty()) q.pop();
					}

				}
			}
		}

		if (!flag) break;

		sorting(map);
		ret++;
	}

	printf("%d\n", ret);
	return 0;
}