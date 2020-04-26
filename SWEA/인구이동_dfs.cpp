#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct yx {
	int y, x;
};

int N, L, R, num, people, answer;
int map[50][50];
bool check[50][50];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
vector<yx> v;

void dfs(int y, int x) {
	check[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		int diff = abs(map[y][x] - map[ny][nx]);
		if (ny<0 || nx<0 || ny>N - 1 || nx > N - 1) continue;
		if (diff >= L && diff <= R && !check[ny][nx]) {
			check[ny][nx] = true;
			people += map[ny][nx];
			num++;
			v.push_back({ ny,nx });
			dfs(ny, nx);
		}
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
					people = map[i][j];
					num = 1;
					v.clear();
					v.push_back({ i, j });
					dfs(i, j);
					if (num >= 2) {
						flag = true;
						for (int i = 0; i < num; i++) {
							map[v[i].y][v[i].x] = people / num;
						}
					}
				}
			}
		}

		if (flag) answer++;
	}
	

	printf("%d\n", answer);
	return 0;
}